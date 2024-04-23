#include "monty.h"
/**
 * openFile - opens a file
 * @fileName: the name of the file to open
 */
void openFile(char *fileName)
{
	FILE *file = fopen(fileName, "r");

	if (!file || !fileName)
	{
		error(2, fileName);
	}
	readFile(file);
	fclose(file);
}

/**
 * readFile - reads a file
 * @fileName: the file to read
 */
void readFile(FILE *fileName)
{
	int line_number, format = 0;
	char buffer[BUFFER_SIZE];

	for (line_number = 1; fgets(buffer, BUFFER_SIZE, fileName) != NULL;
		 line_number++)
	{
		/* Remove the newline character if present */
		size_t len = strlen(buffer);

		if (len > 0 && buffer[len - 1] == '\n')
		{
			buffer[len - 1] = '\0';
		}

		/* Process the line */
		format = parseLine(buffer, line_number, format);
	}
}

/**
 * parseLine - separtates the line into tokens
 * @line: the line to parse
 * @lineNumber: the number of the line
 * @formate: the formate of the line
 * if 0 will be entered to stack and 1 will entered in queue
 * Return: 0 if opcode is stack and 1 if opcode is queue
 */
int parseLine(char *line, int lineNumber, int formate)
{
	char *op, *arg;
	const char *newLine = "\n ";

	if (line == NULL)
		error(4);

	op = strtok(line, newLine);
	if (op == NULL)
		return (formate);
	arg = strtok(NULL, newLine);

	if (strcmp(op, "stack") == 0)
		return (0);
	if (strcmp(op, "queue") == 0)
		return (1);

	findFunction(op, arg, lineNumber, formate);
	return (formate);
}
/**
 * findFunction - finds the function to call
 * @op: the opcode to find
 * @arg: the argument to pass to the function
 * @line: the number of the line
 * @formate: the formate of the line 1 for queue 0 for stack
 */
void findFunction(char *op, char *arg, int line, int formate)
{
	int i, flag;

	instruction_t func_list[] = {
		{"push", push_stack},
		{"pall", pall_print},
		{"pint", printTop},
		{"pop", pop},
		{"nop", nop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"div", div_stack},
		{"mul", mul},
		{"mod", mod},
		{"pchar", printCharacter},
		{"pstr", printString},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}};

	if (op[0] == '#')
		return;

	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(op, func_list[i].opcode) == 0)
		{
			callFunction(func_list[i].f, op, arg, line, formate);
			flag = 0;
		}
	}
	if (flag == 1)
		error(3, line, op);
}

/**
 * callFunction - Calls the required function.
 * @func: Pointer to the function that is about to be called.
 * @opcode: string representing the opcode.
 * @value: string representing a numeric value.
 * @line: line numeber for the instruction.
 * @formate: Format specifier.
 */
void callFunction(f func, char *opcode, char *value, int line, int formate)
{
	stack_t *node;
	int flag, i;

	flag = 1;
	if (strcmp(opcode, "push") == 0)
	{
		if (value != NULL && value[0] == '-')
		{
			value = value + 1;
			flag = -1;
		}
		if (value == NULL)
			error(5, line);
		for (i = 0; value[i] != '\0'; i++)
		{
			if (isdigit(value[i]) == 0)
				error(5, line);
		}
		node = createNode(atoi(value) * flag);
		if (formate == 0)
			func(&node, line);
		if (formate == 1)
			push_queue(&node, line);
	}
	else
		func(&header, line);
}

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
	int lineNumber, formate = 0;
	char *line = NULL;
	size_t lenght = 0;

	for (lineNumber = 1; getline(&line, &lenght, fileName) != -1; lineNumber++)
	{
		/*

		if (lenChars(line) == 0)
			continue;
		parseLine(line, lineNumber, formate);
		*/
		formate = parseLine(line, lineNumber, formate);
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
	char *opcode, *arg;
	const char *newLine = "\n ";

	if (line == NULL)
	{
		error(4);
	}
	opcode = strtok(line, newLine);
	if (opcode == NULL)
		return (formate);
	arg = strtok(NULL, newLine);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);
	findFunction(opcode, arg, lineNumber, formate);
	return (formate);
}
/**
 * findFunction - finds the function to call
 * @op: the opcode to find
 * @arg: the argument to pass to the function
 * @lineNumber: the number of the line
 * @formate: the formate of the line 1 for queue 0 for stack
 */
void findFunction(char *op, char *arg, int lineNumber, int formate)
{
	int i;
	int flag;

	instruction_t func_list[] = {
		{"push", push_stack},
		{"pall", pall},
		{"pint", printTop},
		{"pop", pop},
		{"nop", nop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"div", div},
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
			call_fun(func_list[i].f, op, arg, lineNumber, formate);
			flag = 0;
		}
	}
	if (flag == 1)
		err(3, lineNumber, op);
}

/**
 * callFunction - calls the function
 * @f: the function to call
 * @opcode: the opcode
 * @value: the argument
 * @lineNumber: the number of the line
 * @formate: the formate of the line
 */
void callFunction(f, char *opcode, char *value, int LineNumber, int formate)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(opcode, "push") == 0)
	{
		if (value != NULL && value[0] == '-')
		{
			value = value + 1;
			flag = -1;
		}
		if (value == NULL)
			err(5, LineNumber);
		for (i = 0; value[i] != '\0'; i++)
		{
			if (isdigit(value[i]) == 0)
				err(5, LineNumber);
		}
		node = createNode(atoi(value) * flag);
		if (formate == 0)
			func(&node, LineNumber);
		if (formate == 1)
			push_queue(&node, LineNumber);
	}
	else
		func(&header, LineNumber);
}
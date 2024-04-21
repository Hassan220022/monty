#include "monty.h"
#include <unistd.h>

/**
 * main - entry point for the monty interpreter
 * @argc: the number of arguments passed to the program
 * @argv: an array of strings containing the arguments
 *
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char **argv)
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 1;
	char *opcode, *arg;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&line, &len, file)) != -1)
	{
		char *end_char;

		// Remove any trailing newline or other characters
		if ((end_char = strchr(line, '\n')) != NULL)
			*end_char = '\0';
		if ((end_char = strchr(line, '$')) != NULL)
			*end_char = '\0';

		opcode = strtok(line, " \t");
		arg = strtok(NULL, " \t");

		if (opcode)
		{
			if (strcmp(opcode, "push") == 0)
			{
				push(&stack, arg, line_number);
			}
			else if (strcmp(opcode, "pall") == 0)
			{
				pall(&stack, line_number);
			}
			else
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
				exit(EXIT_FAILURE);
			}
		}
		line_number++;
	}

	fclose(file);
	free(line);
	/* Cleanup any remaining elements in the stack */
	while (stack != NULL)
	{
		stack_t *temp = stack;
		stack = stack->next;
		free(temp);
	}
	return 0;
}

#include "monty.h"
stack_t *header = NULL;

/**
 * main - entry point for the monty interpreter
 * @argc: the number of arguments passed to the program
 * @argv: an array of strings containing the arguments
 *
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char **argv)
{

	if (argc != 2)
	{
		write(STDERR_FILENO, "USAGE: monty file\n", 18);
		exit(EXIT_FAILURE);
	}
	openFile(argv[1]);
	freeNodes();
	return (EXIT_SUCCESS);
}

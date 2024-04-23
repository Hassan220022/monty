#include "monty.h"

/**
 * error - Prints appropiate error messages determined by their error code.
 * @errorCode: The error codes are the following:
 * (1) => The user does not give any file or more than one file to the program.
 * (2) => The file provided is not a file that can be opened or read.
 * (3) => The file provided contains an invalid instruction.
 * (4) => When the program is unable to malloc more memory.
 * (5) => When the parameter passed to the instruction "push" is not an int.
 * (6) => When the stack it empty for pint.
 * (7) => When the stack it empty for pop.
 * (8) => When stack is too short for operation.
 */
void error(int errorCode, ...)
{
	va_list args;
	char *file_name;
	int line_number;

	va_start(args, errorCode);

	switch (errorCode)
	{
	case 1:
		fprintf(stderr, "USAGE: monty file\n");
		break;
	case 2:
		fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(args, char *));
		break;
	case 3:
		line_number = va_arg(args, int);
		file_name = va_arg(args, char *);
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, file_name);
		break;
	case 4:
		fprintf(stderr, "Error: malloc failed\n");
		break;
	case 5:
		fprintf(stderr, "L%d: usage: push integer\n", va_arg(args, int));
		break;
	default:
		break;
	}
	freeNodes();
	exit(EXIT_FAILURE);
}

/**
 * error_more - Prints error mesages according to the error code
 * @errorCode: the error code
 * (6) => When the stack it empty for pint.
 * (7) => When the stack it empty for pop.
 * (8) => When stack is too short for operation.
 * (9) => Division by zero.
 * (10) => The number inside a node is outside ASCII bounds.
 * (11) => The stack is empty.
 */
void error_more(int errorCode, ...)
{
	va_list args;
	char *file_name;
	int line_number;

	va_start(args, errorCode);
	switch (errorCode)
	{
	case 6:
		fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(args, int));
		break;
	case 7:
		fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(args, int));
		break;
	case 8:
		line_number = va_arg(args, unsigned int);
		file_name = va_arg(args, char *);
		fprintf(stderr, "L%d: can't %s, stack too short\n", line_number, file_name);
		break;
	case 9:
		fprintf(stderr, "L%d: division by zero\n",
				va_arg(args, unsigned int));
		break;
	case 10:
		line_number = va_arg(args, int);
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		break;
	case 11:
		line_number = va_arg(args, int);
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		break;
	default:
		break;
	}
	freeNodes();
	exit(EXIT_FAILURE);
}

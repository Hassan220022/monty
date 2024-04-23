#include "monty.h"

/**
 * error - Prints error mesages according to the error code
 * @errorCode: the error code
 * (1) => no given file or more than one file to the program
 * (2) => can't open file
 * (3) => file provied have invalid instruction
 * (4) => program cann't allocat more memory
 * (5) => invalid argument || invalid data type to be pushed
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
		file_name = va_arg(args, char *);
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		break;
	case 3:
		line_number = va_arg(args, int);
		fprintf(stderr, "L%d: unknown instruction\n", line_number);
		break;
	case 4:
		fprintf(stderr, "Error: malloc failed\n");
		break;
	case 5:
		line_number = va_arg(args, int);
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		break;
	default:
		fprintf(stderr, "Unknown error\n");
	}

	va_end(args);
	exit(EXIT_FAILURE);
}

/**
 * error_more - Prints error mesages according to the error code
 * @errorCode: the error code
 * @line_number: the line number
 * (6) => can't print an empty stack
 * (7) => can't pop an empty stack
 * (8) => can't swap, short stack
 * (9) => can't divide by zero
 * (10) => The number inside a node is outside ASCII bounds.
 * (11) => The stack is empty.
 */
void error_more(int errorCode, int line_number, ...)
{
	if (line_number < 0)
	{
		fprintf(stderr, "Error: Line number is invalid\n");
		exit(EXIT_FAILURE);
	}

	switch (errorCode)
	{
	case 6:
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		break;
	case 7:
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		break;
	case 8:
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		break;
	case 9:
		fprintf(stderr, "L%d: division by zero\n", line_number);
		break;
	case 10:
		fprintf(stderr, "L%d: value out of ASCII bounds\n", line_number);
		break;
	case 11:
		fprintf(stderr, "L%d: stack empty\n", line_number);
		break;
	default:
		fprintf(stderr, "Unknown error\n");
	}

	exit(EXIT_FAILURE);
}

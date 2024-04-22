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
	char *operator;
	int line_number;

	va_start(args, errorCode);
	switch (errorCode)
	{
	case 1:
		fprintf(stderr, "USAGE: monty file\n");
		break;
	case 2:
		fprintf(stderr, "Error: Can't open file %s\n", operator);
		va_arg(args, char *);
		break;
	case 3:
		line_number = va_arg(args, int);
		operator = va_arg(args, char *);
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, operator);
		break;
	case 4:
		fprintf(stderr, "Error: malloc failed\n");
		break;
	case 5:
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
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
 * (6) => can't print an empty stack
 * (7) => can't pop an empty stack
 * (8) => can't swap, short stack
 * (9) => can't divide by zero
 * (10) => The number inside a node is outside ASCII bounds.
 * (11) => The stack is empty.
 */
void error_more(int errorCode, ...)
{
	va_list args;
	char *operator;
	int line_number;

	va_start(args, errorCode);
	switch (errorCode)
	{
	case 6:
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		va_arg(args, int);
		break;
	case 7:
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		va_arg(args, int);
		break;
	case 8:
		line_number = va_arg(args, int);
		operator = va_arg(args, char *);
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		break;
	case 9:
		fprintf(stderr, "L%d: division by zero\n", line_number);
		va_arg(args, unsigned int);
		break;
	case 10:
		fprintf(stderr, "L%d: can't putchar, value out of range\n", line_number);
		break;
	case 11:
		fprintf(stderr, "L%d: can't putchar, empty stack\n", line_number);
		break;
	default:
		break;
	}
	freeNodes();
	exit(EXIT_FAILURE);
}

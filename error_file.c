#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "monty.h"

/**
 * error - Prints error mesages according to the error code
 * @errorCode: the error code
 * @LineNumber: the line number
 * (1) => no given file or more than one file to the program
 * (2) => can't open file
 * (3) => file provied have invalid instruction
 * (4) => program cann't allocat more memory
 * (5) => invalid argument || invalid data type to be pushed
 */
void error(int errorCode, int LineNumber, ...)
{
	va_list args;
	char *file_name;

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
		LineNumber = va_arg(args, int);
		fprintf(stderr, "L%d: unknown instruction\n", LineNumber);
		break;
	case 4:
		fprintf(stderr, "Error: malloc failed\n");
		break;
	case 5:
		LineNumber = va_arg(args, int);
		fprintf(stderr, "L%d: usage: push integer\n", LineNumber);
		break;
	default:
		fprintf(stderr, "Unknown error\n");
		break;
	}

	va_end(args);
	exit(EXIT_FAILURE);
}

/**
 * error_more - Prints error mesages according to the error code
 * @errorCode: the error code
 * @LineNumber: the line number
 * (6) => can't print an empty stack
 * (7) => can't pop an empty stack
 * (8) => can't swap, short stack
 * (9) => can't divide by zero
 * (10) => The number inside a node is outside ASCII bounds.
 * (11) => The stack is empty.
 */
void error_more(int errorCode, int LineNumber, ...)
{
	va_list args;

	va_start(args, errorCode);

	switch (errorCode)
	{
	case 6:
		fprintf(stderr, "L%d: can't pint, stack empty\n", va_arg(args, int));
		break;
	case 7:
		fprintf(stderr, "L%d: can't pop an empty stack\n", va_arg(args, int));
		break;
	case 8:
		fprintf(stderr, "L%d: can't swap, stack too short\n", va_arg(args, int));
		break;
	case 9:
		fprintf(stderr, "L%d: division by zero\n", va_arg(args, int));
		break;
	case 10:
		fprintf(stderr, "L%d: value out of ASCII bounds\n", va_arg(args, int));
		break;
	case 11:
		fprintf(stderr, "L%d: stack empty\n", va_arg(args, int));
		break;
	default:
		fprintf(stderr, "Unknown error\n");
		break;
	}

	va_end(args);
	exit(EXIT_FAILURE);
}

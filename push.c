#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: double pointer to the head of the stack
 * @line_number: the line number of the command being run
 * @arg: the argument to push onto the stack
 */
void push(stack_t **stack, char *arg, unsigned int line_number)
{
	stack_t *new_node;
	int num;

	if (arg == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	/*Converts string to integer, assumes valid conversion for now*/
	num = atoi(arg);
	if (*arg == '\0' || (*arg == '0' && arg[1] != '\0'))
	{ /* Checks if atoi failed to convert a number */
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = num;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}

/**
 * pall_print - prints all the values on the stack, starting from top
 * @stack: double pointer to the head of the stack
 * @line_number: the line number of the command being run
 */
void pall_print(stack_t **stack, unsigned int line_number)
{
	(void)line_number; /* Ignore unused parameter */

	{
		stack_t *current = *stack;

		while (current != NULL)
		{
			printf("%d\n", current->n);
			current = current->next;
		}
	}
}

#include "monty.h"

/**
 * push_stack - push a node to the stack
 * @stack: the stack
 * @n: the number to push
 */
void push_stack(stack_t **stack, __attribute__((unused)) unsigned int n)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
		exit(EXIT_FAILURE);
	if (header == NULL)
	{
		header = *stack;
		return;
	}
	temp = header;
	header = *stack;
	header->next = temp;
	temp->prev = header;
}

/**
 * pall - prints all the values on the stack
 * @stack: the stack
 * @LineNumber: the line number
 */
void pall(stack_t **stack, unsigned int LineNumber)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
		exit(EXIT_FAILURE);
	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
	(void)LineNumber;
}

/**
 * pop - removes the top element of the stack
 * @stack: the stack
 * @LineNumber: the line number
 */
void pop(stack_t **stack, unsigned int LineNumber)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
		error_more(7, LineNumber);
	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}

/**
 * printTop - prints the top element of the stack
 * @stack: the stack
 * @LineNumber: the line number
 */
void printTop(stack_t **stack, unsigned int LineNumber)
{
	if (stack == NULL || *stack == NULL)
		error_more(6, LineNumber);
	printf("%d\n", (*stack)->n);
}

#include "monty.h"

/**
 * swap - Swaps the first two elements of the stack
 * @stack: the stack
 * @LineNumber: the line number
 */
void swap(stack_t **stack, unsigned int LineNumber)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		error_more(8, LineNumber, "swap");
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}

/**
 * nop - Does nothing
 * @stack: the stack
 * @LineNumber: the line number
 */
void nop(stack_t **stack, unsigned int LineNumber)
{
	(void)stack;
	(void)LineNumber;
}

/**
 * add - adds elements of the stack
 * @stack: the stack
 * @LineNumber: the line number
 */
void add(stack_t **stack, unsigned int LineNumber)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		error_more(8, LineNumber, "add");

	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * sub - subtracts elements of the stack
 * @stack: the stack
 * @LineNumber: the line number
 */
void sub(stack_t **stack, unsigned int LineNumber)
{
	int sub;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		error_more(8, LineNumber, "sub");

	(*stack) = (*stack)->next;
	sub = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sub;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
/**
 * div_stack - divides elements of the stack
 * @stack: the stack
 * @LineNumber: the line number
 */
void div_stack(stack_t **stack, unsigned int LineNumber)
{
	int div;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		error_more(8, LineNumber, "div");

	if ((*stack)->n == 0)
		error_more(9, LineNumber);

	(*stack) = (*stack)->next;
	div = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = div;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

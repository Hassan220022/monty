#include "monty.h"

/**
 * mul - multiplies elements of the stack
 * @stack: the stack
 * @LineNumber: the line number
 */
void mul(stack_t **stack, unsigned int LineNumber)
{
	int mul;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, LineNumber, "mul");

	(*stack) = (*stack)->next;
	mul = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = mul;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
/**
 * mod - modules elements of the stack
 * @stack: the stack
 * @LineNumber: the line number
 */
void mod(stack_t **stack, unsigned int LineNumber)
{
	int mod;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, LineNumber, "mod");

	if ((*stack)->n == 0)
		more_err(9, LineNumber);

	(*stack) = (*stack)->next;
	mod = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = mod;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

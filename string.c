#include "monty.h"
/**
 * printCharacter - prints the character at the top of the stack
 * @stack: the stack
 * @LineNumber: the line number
 */
void printCharacter(stack_t **stack, unsigned int LineNumber)
{
	stack_t *temp = *stack;

	if (stack == NULL || *stack == NULL)
	{
		more_err(11, LineNumber);
	}
	if (temp->n < 0 || temp->n > 127)
	{
		more_err(10, LineNumber);
	}
	printf("%c\n", temp->n);
}
/**
 * printString - prints the string starting at the top of the stack
 * @stack: the stack
 * @LineNumber: the line number
 */
void printString(stack_t **stack, unsigned int LineNumber)
{
	stack_t *temp = *stack;

	if (stack == NULL || *stack == NULL)
	{
		more_err(11, LineNumber);
	}
	while (temp != NULL && temp->n != 0 && (temp->n > 0 && temp->n <= 127))
	{
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
}
/**
 * rotl - rotates the first node of the stack to the last
 * @stack: the stack
 * @LineNumber: the line number
 */
void rotl(stack_t **stack, __attribute__((unused)) unsigned int LineNumber)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	temp = *stack;

	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *stack;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*stack)->prev = temp;
	(*stack) = temp;
}
/**
 * rotr - Rotates the last node of the stack to the top.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @LineNumber: Interger representing the line number of of the opcode.
 */
void rotr(stack_t **stack, __attribute__((unused)) unsigned int LineNumber)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	temp = *stack;

	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *stack;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*stack)->prev = temp;
	(*stack) = temp;
}

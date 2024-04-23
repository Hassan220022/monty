#include "monty.h"
/**
 * createNode - creates a new node
 * @number: the number to add to the node
 * Return: the new node
 */
stack_t *createNode(int number)
{
	stack_t *newNode = malloc(sizeof(stack_t));

	if (newNode == NULL)
	{
		error(4, 0);
	}
	newNode->n = number;
	newNode->next = NULL;
	newNode->prev = NULL;
	return (newNode);
}
/**
 * freeNodes - frees the nodes
 */
void freeNodes(void)
{
	stack_t *temp = header;

	while (header != NULL)
	{
		temp = header;
		header = header->next;
		free(temp);
	}
}

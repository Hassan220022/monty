#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *header;
typedef void (*f)(stack_t **stack, unsigned int line_number);

/* file.c */
void openFile(char *);
void readFile(FILE *);
int lenChars(char *);
void parseLine(char *, int, int);
void findFunction(char *, int, int);

/* Stack operations.c */
stack_t *createNode(int);
void freeNodes(void);
void printStack(stack_t **, unsigned int);
void addStack(stack_t **, int);
void addQueue(stack_t **, int);

void callFunction(f, stack_t **, unsigned int);

#endif /* MONTY_H */

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
int parseLine(char *, int, int);
void findFunction(char *, char *, int, int);
void callFunction(f, char *, char *, int, int);

/* Operation */
/* Stack_1.c */
void push_stack(stack_t **, __attribute__((unused)) unsigned int);
void push_queue(stack_t **, int);
void pall(stack_t **, unsigned int);
void pop(stack_t **, unsigned int);
void printTop(stack_t **, unsigned int);
/* Stack_2.c */
stack_t *createNode(int);
void freeNodes(void);

/* math_1.c */
void nop(stack_t **, unsigned int);
void swap(stack_t **, unsigned int);
void add(stack_t **, unsigned int);
void sub(stack_t **, unsigned int);
void div_stack(stack_t **, unsigned int);
/* math_2.c*/
void mul(stack_t **, unsigned int);
void mod(stack_t **, unsigned int);

/* String_operation.c*/
void printCharacter(stack_t **, unsigned int);
void printString(stack_t **, unsigned int);
void rotl(stack_t **, unsigned int);
void rotr(stack_t **, unsigned int);

/* Error Handeling */
/* error_file.c */
void error(int, ...);
void error_more(int, int, ...);

#endif /* MONTY_H */

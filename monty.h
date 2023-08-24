#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* GLOBAL OPCODE TOKENS */
extern char **op_c;

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

extern stack_t *top;

void push(stack_t **stack, unsigned int value);
void pop(stack_t **stack, unsigned int line_num);
void pall(stack_t **stack, unsigned int line_num);
void process_instruction(instruction_t *instructs, char *opcode,
		int argument, unsigned int line_num);
void process_file(const char *filename, instruction_t *instructs);
#endif

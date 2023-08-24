#include "monty.h"

/**
 * add - Adds the top two elements of the stack
 * @stack: Pointer to the top of the stack
 * @line_num: Line number in the Monty code file
 */
void add(stack_t **stack, unsigned int line_num)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	pop(stack, line_num);
}


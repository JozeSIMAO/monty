#include "monty.h"

/**
 * pop - pops an element from the stack
 * @stack: is double pointer to the stack
 * @line_number: is the number of the line we read
 * Return: void
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (*stack != NULL)
	{
		*stack = (*stack)->next;

		if (*stack != NULL)
			(*stack)->prev = NULL;
		free(temp);
	}
	else
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
}

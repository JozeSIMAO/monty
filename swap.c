#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack
 * @stack: Pointer to the top of the stack
 * @line_num: Line number in the Monty code file
 */
void swap(stack_t **stack, unsigned int line_num)
{
	stack_t *first, *second;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	first = *stack;
	second = (*stack)->next;

	first->prev = second;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;

	*stack = second;
}


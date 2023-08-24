#include "monty.h"

/**
 * pint - prints the top value of a stack_t linked list
 * @stack: pointer to the top of a stack
 * @line_num:line we're reading
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_num)
{
	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->next->n);
}

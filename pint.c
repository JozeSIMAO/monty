#include "monty.h"

/**
 * pint - Prints the top value of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_num: The current working line number of a Monty bytecodes file.
 *
 * Return: Nothing (void).
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


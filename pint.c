#include "monty.h"

/**
 * pint - prints the value at the top of the stack
 * @stack: is pointer to top of the stack
 * @linee_num: line number
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_num)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

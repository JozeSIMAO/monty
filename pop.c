#include "monty.h"
/**
 * pop - removes the top element from the stack
 * @stack: pointer to the top of the stack
 * @line_num: line number
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;

	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}

	free(temp);
}

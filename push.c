#include "monty.h"

/**
 * push - pushes an element onto the stack
 * @stack: pointer to the top of the stack
 * @value: value to push
 * Return: void
 */
void push(stack_t **stack, unsigned int value)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;

	if (*stack == NULL)
	{
		new_node->next = NULL;
	}
	else
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}

	*stack = new_node;
}

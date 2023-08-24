#include "monty.h"

/**
 * push - pushes a new element onto the stack
 * @stack: is double pointer to stack
 * @value: is data value of new element
 * Return: void
 */
void push(stack_t **stack, unsigned int value)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		perror("Error allocating memory");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->next = *stack;
	new_node->prev = NULL;

	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}

	*stack = new_node;
}

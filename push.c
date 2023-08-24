#include "monty.h"

/**
 * push - pushes a new element to the stack
 * @stack: pointer to the top node in the stack
 * @line_num: The current working line number of a Monty bytecodes file
 * Return: void
 */
void push(stack_t **stack, unsigned int line_num)
{
	stack_t *temp, *new_node;
	int i;

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	if (op_c[1] == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_num);
		exit(EXIT_FAILURE);
	}

	for (i = 0; op_c[1][i]; i++)
	{
		if (op_c[1][i] == '-' && i == 0)
			continue;
		if (op_c[1][i] < '0' || op_c[1][i] > '9')
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_num);
			exit(EXIT_FAILURE);
		}
	}
	new_node->n = atoi(op_c[1]);

	temp = (*stack)->next;
	new_node->prev = *stack;
	new_node->next = temp;
	if (temp)
		temp->prev = new_node;
	(*stack)->next = new_node;
}


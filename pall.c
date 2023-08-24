#include "monty.h"
/**
 * pall - prints all elements in the stack
 * @stack: pointer to the top of the stack
 * @line_num: line number
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_num)
{
	stack_t *temp = *stack;
	(void)line_num;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

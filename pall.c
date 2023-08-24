#include "monty.h"
/**
 * pall - Prints the values of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_num: The current working line number of a Monty bytecodes file.
 */
void pall(stack_t **stack, unsigned int line_num)
{
    stack_t *tmp = (*stack)->next;
    (void)line_num;

    while (tmp)
    {
        printf("%d\n", tmp->n);
        tmp = tmp->next;
    }
}
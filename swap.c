#include "monty.h"
/**
 * monty_swap - Swaps the top two value elements of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_num: The current working line number of a Monty bytecodes file.
 */
void swap(stack_t **stack, unsigned int line_num)
{
    stack_t *temp;


    if ((*stack)->next == NULL || (*stack)->next->next == NULL)
    {
        fprintf(stderr, "L%u: can't swap, stack too short\n",line_num);
        exit(EXIT_FAILURE);
    }


    temp = (*stack)->next->next;
    (*stack)->next->next = temp->next;
    (*stack)->next->prev = temp;

    if (temp->next)
    {
        temp->next->prev = (*stack)->next;
    }

    temp->next = (*stack)->next;
    temp->prev = *stack;

    (*stack)->next = temp;
}
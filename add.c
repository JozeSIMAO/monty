#include "monty.h"

/**
 * add - Adds the top two values of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_num: The current working line number of a Monty bytecodes file.
 *
 * Return: void
 */
void add(stack_t **stack, unsigned int line_num)
{
    if ((*stack)->next == NULL || (*stack)->next->next == NULL)
    {
        fprintf(stderr, "L%u: can't add, stack too short\n", line_num);
        return;
    }

    (*stack)->next->next->n += (*stack)->next->n;
    pop(stack, line_num);
}
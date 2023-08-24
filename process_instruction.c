#include "monty.h"
/**
 * process_instruction - processes opcode & its arguments
 * @instructs: pointer to struct of instructions
 * @opcode: monty code
 * @argument: argument
 * @line_num: line number
 * Return: void
 */
void process_instruction(instruction_t *instructs, char *opcode,
		int argument, unsigned int line_num)
{
	int i;
	(void)argument;

	for (i = 0; instructs[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, instructs[i].opcode) == 0)
		{
			instructs[i].f(&top, line_num);
			return;
		}
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line_num, opcode);
	exit(EXIT_FAILURE);
}

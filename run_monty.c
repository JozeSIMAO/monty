#include "monty.h"

stack_t *top = NULL;
/**
 * main - Entry point for Monty interpreter execution
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 * Return: Exit status
 */
int main(int argc, char *argv[])
{
	instruction_t instructions[] = {
		{"push", push},
		{"pop", pop},
		{"pall", pall},
		{"pint", pint},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
		return (EXIT_FAILURE);
	}

	process_file(argv[1], instructions);

	while (top != NULL)
	{
		pop(&top, 0);
	}

	return (EXIT_SUCCESS);
}

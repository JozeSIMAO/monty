#include "monty.h"

/**
 * main - Entry point for Monty interpreter execution
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 * Return: Exit status
 */
char **op_c;
stack_t *top = NULL;
int main(int argc, char *argv[])
{
	instruction_t instructions[] = {
		{"push", push},
		{"pop", pop},
		{"pall", pall},
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

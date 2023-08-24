#include "monty.h"
/**
 * main - main function, runs all functions to interprete monty
 * @argc: number of commandline arguments
 * @argv: array of arguments
 * Return: 0 success
 */

int main(int argc, char *argv[])
{
	instruction_t instructions[] = {
		{"push", push},
		{"pop", pop},
		{"pall", pall},
		{"pall$", pall},
		{NULL, NULL}
	};
	top = NULL;

	if (argc != 2)
	{
		printf("Usage: %s <input_file>\n", argv[0]);
		return (1);
	}

	process_file(argv[1], instructions);

	while (top != NULL)
	{
		pop(&top, 0);
	}

	return (0);
}

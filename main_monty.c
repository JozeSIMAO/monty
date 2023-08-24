#include "monty.h"
char **op_c = NULL;

/**
 * main - Main function
 * @argc: Number of command line arguments
 * @argv: Pointer to an array of char pointers to arguments
 * Return: 1 or 0
 */
int main(int argc, char **argv)
{
	FILE *file = NULL;
	int exit_code = EXIT_SUCCESS;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
	}

	exit_code = run_monty(file);

	fclose(file);

	return (exit_code);
}


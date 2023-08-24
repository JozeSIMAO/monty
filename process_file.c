#include "monty.h"
/**
 * process_file - processes file and executes instructions
 * @filename: name of the file we're reading
 * @instructs: pointer to struct of instructions
 * Return: void
 */
void process_file(const char *filename, instruction_t *instructs)
{
	FILE *file = fopen(filename, "r");
	char line[256], *opcode, *token;
	unsigned int line_num = 0;
	int argument;

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), file))
	{
		line_num++;
		opcode = strtok(line, " \t$\n");

		if (opcode != NULL)
		{
			token = strtok(NULL, " \t$\n");
			argument = token ? atoi(token) : 0;
			process_instruction(instructs, opcode, argument, line_num);
		}
	}
	fclose(file);
}
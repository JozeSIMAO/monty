#include "monty.h"

/**
 * process_instruction - processes opcode and its arguments
 * @instructs: pointer to struct of instructions
 * @opcode: monty code
 * @arg: argument
 * @line_num: line number we're reading
 * Return: void
 */
void process_instuction(instruction_t *instructs, unsigned int line_num)
{
	int i = 0;

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

/**
 * process_file - processes file and executes instructions
 * @filename: name of the file we're reading
 * @instructs: pointer to struct of instructions
 * Return: void
 */

void process_file(const char *filename, instruction_t *instructs)
{
	FILE *file = fopen(filename, "r");
	char line[256], *token;
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
		token = strtok(line, " \t\n");

		if (token != NULL)
		{
			*opcode = token;
			token = strtok(NULL, " \t\n");
			argument = token ? atoi(token) : 0;
			process_instruction(instructions, line_num);
		}
	}

	fclose(file);
}

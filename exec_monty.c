#include "monty.h"

char **strtow(char *str, char *delims);
int is_delim(char ch, char *delims);
int get_word_length(char *str, char *delims);
int get_word_count(char *str, char *delims);
char *get_next_word(char *str, char *delims);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
/**
 * free_tokens - Frees the global op_c array of strings.
 * Return: void
 */
void free_tokens(void)
{
	size_t i = 0;

	if (op_c == NULL)
		return;

	for (i = 0; op_c[i]; i++)
		free(op_c[i]);

	free(op_c);
}

/**
 * token_arr_len - Gets the length of current op_toks.
 * Return: void
 */
unsigned int token_arr_len(void)
{
	unsigned int toks_len = 0;

	while (op_c[toks_len])
		toks_len++;
	return (toks_len);
}

/**
 * is_empty_line - Checks if a line read from getline only contains delimiters.
 * @line: line we're reading
 * @delims: delimiter we're using
 * Return: int
 */
int is_empty_line(char *line, char *delims)
{
	int i, j;

	for (i = 0; line[i]; i++)
	{
		for (j = 0; delims[j]; j++)
		{
			if (line[i] == delims[j])
				break;
		}
		if (delims[j] == '\0')
			return (0);
	}

	return (1);
}

/**
 * get_op_func - Matches an opcode with its corresponding function.
 * @opcode: opcode
 * Return: void
 */
void (*get_op_func(char *opcode))(stack_t**, unsigned int)
{
	instruction_t op_funcs[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};
	int i;

	for (i = 0; op_funcs[i].opcode; i++)
	{
		if (strcmp(opcode, op_funcs[i].opcode) == 0)
			return (op_funcs[i].f);
	}

	return (NULL);
}

/**
 * run_monty - Primary function to execute a Monty bytecodes script.
 * @file: monty file
 * Return: int
 */
int run_monty(FILE *file)
{
	stack_t *stack = NULL;
	char *line = NULL;
	size_t len = 0, exit_status = EXIT_SUCCESS;
	unsigned int line_num = 0, prev_tok_len = 0;
	void (*op_func)(stack_t**, unsigned int);

	if (init_stack(&stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	while (getline(&line, &len, file) != -1)
	{
		line_num++;
		op_c = strtow(line, DELIMS);
		if (op_c == NULL)
		{
			if (is_empty_line(line, DELIMS))
				continue;
			free_stack(&stack);
			fprintf(stderr, "Error: malloc failed\n");
			return (EXIT_FAILURE);
		}
		else if (op_c[0][0] == '#')
		{
			free_tokens();
			continue;
		}
		op_func = get_op_func(op_c[0]);
		if (op_func == NULL)
		{
			free_stack(&stack);
			fprintf(stderr, "L%u: unknown instruction %s\n",
				line_num, op_c[0]);
			exit(EXIT_FAILURE);
			free_tokens();
			break;
		}
		prev_tok_len = token_arr_len();
		op_func(&stack, line_num);
		if (token_arr_len() != prev_tok_len)
		{
			if (op_c && op_c[prev_tok_len])
				exit_status = atoi(op_c[prev_tok_len]);
			else
				exit_status = EXIT_FAILURE;
			free_tokens();
			break;
		}
		free_tokens();
	}
	free_stack(&stack);
	if (line && *line == 0)
	{
		free(line);
		fprintf(stderr, "Error: malloc failed\n");
		return (EXIT_FAILURE);
	}
	free(line);
	return (exit_status);
}


#include <stdlib.h>
char **strtow(char *str, char *delims);
int is_delim(char ch, char *delims);
int get_word_length(char *str, char *delims);
int get_word_count(char *str, char *delims);
char *get_next_word(char *str, char *delims);

/**
 * strtow - Splits a string into an array of substrings.
 * @str: String.
 * @delim: Delimiter.
 *
 * Return: Array of pointers to words.
 */
char **strtow(char *str, char *delim)
{
	char **words = NULL;
	int wc, len, n, i = 0;

	if (str == NULL || !*str)
		return (NULL);
	wc = get_word_count(str, delim);
	if (wc == 0)
		return (NULL);
	words = malloc((wc + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);

	while (i < wc)
	{
		len = get_word_length(str, delim);
		if (is_delim(*str, delim))
			str = get_next_word(str, delim);
		words[i] = malloc((len + 1) * sizeof(char));
		if (words[i] == NULL)
		{
			while (i >= 0)
			{
				i--;
				free(words[i]);
			}
			free(words);
			return (NULL);
		}
		n = 0;
		while (n < len)
		{
			words[i][n] = *(str + n);
			n++;
		}
		words[i][n] = '\0';
		str = get_next_word(str, delim);
		i++;
	}
	words[i] = NULL;
	return (words);
}

/**
 * is_delim - Checks if a character is a delimiter.
 * @chr: Character to check.
 * @delim: Pointer to array of delimiters.
 *
 * Return: 1 if delimiter, 0 otherwise.
 */
int is_delim(char chr, char *delim)
{
	int i = 0;

	while (delim[i])
	{
		if (delim[i] == chr)
			return (1);
		i++;
	}
	return (0);
}

/**
 * get_word_length - Gets the length of a word.
 * @str: String to get word length from current word.
 * @delim: Delimiter to use.
 *
 * Return: Length of the word.
 */
int get_word_length(char *str, char *delim)
{
	int len = 0, pending = 1, i = 0;

	while (*(str + i))
	{
		if (is_delim(str[i], delim))
			pending = 1;
		else if (pending)
		{
			len++;
		}
		if (len > 0 && is_delim(str[i], delim))
			break;
		i++;
	}
	return (len);
}

/**
 * get_word_count - Gets the word count of a string.
 * @str: String to get word count from.
 * @delim: Delimiters to use to delimit words.
 *
 * Return: The word count of the string.
 */
int get_word_count(char *str, char *delim)
{
	int wc = 0, pending = 1, i = 0;

	while (*(str + i))
	{
		if (is_delim(str[i], delim))
			pending = 1;
		else if (pending)
		{
			pending = 0;
			wc++;
		}
		i++;
	}
	return (wc);
}

/**
 * get_next_word - Gets the next word in a string.
 * @str: String to get next word from.
 * @delim: Delimiters to use to delimit words.
 *
 * Return: Pointer to the first character of the next word.
 */
char *get_next_word(char *str, char *delim)
{
	int pending = 0;
	int i = 0;

	while (*(str + i))
	{
		if (is_delim(str[i], delim))
			pending = 1;
		else if (pending)
			break;
		i++;
	}
	return (str + i);
}

#include "shell.h"

/**
 * read_line - reads input from stdin
 * Return: pointer to the string or NULL
 */
char *read_line(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t n;

	n = getline(&line, &len, stdin);
	if (n == -1)
	{
		free(line);
		return (NULL);
	}
	if (line[n - 1] == '\n')
		line[n - 1] = '\0';

	return (line);
}

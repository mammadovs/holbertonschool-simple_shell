#include "shell.h"

/**
 * read_line - reads a line from stdin
 *
 * Return: pointer to line, or NULL on EOF
 */
char *read_line(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read_chars;

	read_chars = getline(&line, &len, stdin);
	if (read_chars == -1)
	{
		free(line);
		return (NULL);
	}

	/* Убираем только последний '\n', если он есть */
	if (read_chars > 0 && line[read_chars - 1] == '\n')
		line[read_chars - 1] = '\0';

	return (line);
}

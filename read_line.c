#include "shell.h"

/**
 * read_line - читает строку из stdin
 * Return: указатель на строку или NULL
 */
char *read_line(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	nread = getline(&line, &len, stdin);
	if (nread == -1)
	{
		free(line);
		return (NULL);
	}

	/* Убираем символ новой строки в конце */
	if (nread > 0 && line[nread - 1] == '\n')
		line[nread - 1] = '\0';

	return (line);
}

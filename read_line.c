#include "shell.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * trim_spaces - убирает пробелы в начале и конце строки
 * @str: исходная строка
 *
 * Return: указатель на "обрезанную" строку
 */
char *trim_spaces(char *str)
{
	char *end;

	if (!str)
		return (NULL);

	/* убираем ведущие пробелы */
	while (*str && (*str == ' ' || *str == '\t'))
		str++;

	/* если строка пустая */
	if (*str == '\0')
		return (str);

	/* убираем пробелы в конце */
	end = str + strlen(str) - 1;
	while (end > str && (*end == ' ' || *end == '\t'))
		end--;

	end[1] = '\0';
	return (str);
}

/**
 * read_line - считывает строку из stdin
 *
 * Return: указатель на строку, или NULL при EOF
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

	/* убираем только последний '\n', если он есть */
	if (read_chars > 0 && line[read_chars - 1] == '\n')
		line[read_chars - 1] = '\0';

	/* убираем пробелы в начале и конце */
	line = trim_spaces(line);

	return (line);
}

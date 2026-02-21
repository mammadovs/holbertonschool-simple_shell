#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * read_line - считывает строку с ввода
 *
 * Return: указатель на строку (необходимо free), или NULL при EOF
 */
char *read_line(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read_chars;
    char *trimmed_line;

    read_chars = getline(&line, &len, stdin);
    if (read_chars == -1)
    {
        free(line);
        return (NULL);
    }

    if (read_chars > 0 && line[read_chars - 1] == '\n')
        line[read_chars - 1] = '\0';

    trimmed_line = trim_spaces(line);

    /* Если trim_spaces сдвигает указатель, делаем копию */
    if (trimmed_line != line)
    {
        char *copy = strdup(trimmed_line);
        free(line);
        return (copy);
    }

    return (line);
}

/**
 * trim_spaces - удаляет ведущие и конечные пробелы строки
 * @str: исходная строка
 *
 * Return: указатель на строку без ведущих/конечных пробелов
 */
char *trim_spaces(char *str)
{
    char *end;

    if (!str)
        return (NULL);

    /* Убираем ведущие пробелы */
    while (*str == ' ' || *str == '\t')
        str++;

    if (*str == 0)  /* строка полностью из пробелов */
        return str;

    /* Убираем конечные пробелы */
    end = str + strlen(str) - 1;
    while (end > str && (*end == ' ' || *end == '\t'))
        end--;

    *(end + 1) = '\0';

    return str;
}

#include "shell.h"

/**
 * read_line - читает строку из стандартного ввода
 * Return: указатель на строку или NULL при EOF
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

    /* Удаляем символ новой строки для корректной работы execve */
    if (nread > 0 && line[nread - 1] == '\n')
    {
        line[nread - 1] = '\0';
    }

    return (line);
}

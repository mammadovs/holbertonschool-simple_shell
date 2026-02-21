#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * read_line - читает строку из stdin
 * Return: указатель на строку (malloc), или NULL при EOF
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
        return NULL;
    }

    return line;
}

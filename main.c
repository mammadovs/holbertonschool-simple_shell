#include "shell.h"

/**
 * main - точка входа в простой шелл
 * Return: всегда 0
 */
int main(void)
{
    char *line;

    while (1)
    {
        if (isatty(STDIN_FILENO))
            display_prompt();

        line = read_line();
        if (!line)
        {
            if (isatty(STDIN_FILENO))
                write(STDOUT_FILENO, "\n", 1);
            exit(0);
        }

        /* Передаем NULL, чтобы избежать ошибок с неиспользуемыми аргументами */
        execute_command(line, NULL, NULL);
        free(line);
    }

    return (0);
}

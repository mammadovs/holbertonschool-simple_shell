#include "shell.h"
#include <stdlib.h>
#include <unistd.h>

/**
 * main - точка входа в простую оболочку
 * @argc: количество аргументов (не используется)
 * @argv: аргументы командной строки
 * @env: переменные окружения
 *
 * Return: 0 при успешном завершении
 */
int main(int argc, char **argv, char **env)
{
    char *line;
    (void)argc;

    while (1)
    {
        if (isatty(STDIN_FILENO))
            display_prompt();

        line = read_line();
        if (!line)
        {
            /* EOF (Ctrl+D) */
            if (isatty(STDIN_FILENO))
                write(STDOUT_FILENO, "\n", 1);
            exit(0);
        }

        if (line[0] != '\0')
            execute_command(line, argv, env);

        free(line);
    }

    return (0);
}

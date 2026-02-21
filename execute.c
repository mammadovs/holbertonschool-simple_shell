#include "shell.h"

/**
 * execute_command - создает процесс и запускает программу
 * @command: путь к исполняемому файлу
 * @argv: массив аргументов (не используется)
 * @env: переменные окружения (не используется)
 * Return: 0 при успехе
 */
int execute_command(char *command, char **argv, char **env)
{
    pid_t child_pid;
    int status;
    char *args[2];

    /* Подавляем ошибки компилятора о неиспользуемых аргументах */
    (void)argv;
    (void)env;

    if (!command || command[0] == '\0')
        return (0);

    child_pid = fork();
    if (child_pid == -1)
    {
        perror("Error");
        return (-1);
    }

    if (child_pid == 0)
    {
        args[0] = command;
        args[1] = NULL;

        if (execve(args[0], args, NULL) == -1)
        {
            perror("./hsh");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        wait(&status);
    }

    return (0);
}

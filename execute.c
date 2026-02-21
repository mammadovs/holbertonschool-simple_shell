#include "shell.h"

int execute_command(char *command, char **argv, char **env)
{
    pid_t child_pid;
    int status;
    char *args[2];

    /* Нам нужно передать аргументы в execve через массив */
    args[0] = command;
    args[1] = NULL;

    if (!command || command[0] == '\0')
        return (0);

    child_pid = fork();
    if (child_pid == -1)
    {
        perror("Error");
        return (-1);
    }
    
    if (child_pid == 0) /* Дочерний процесс */
    {
        /* Запускаем команду. Если ошибка — выводим сообщение */
        if (execve(args[0], args, env) == -1)
        {
            perror("./hsh");
            exit(EXIT_FAILURE);
        }
    }
    else /* Родительский процесс */
    {
        wait(&status);
    }

    return (0);
}

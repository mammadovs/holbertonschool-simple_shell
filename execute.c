#include "shell.h"

int execute_command(char *line, char **argv, char **env)
{
    pid_t child_pid;
    int status;
    char *args[2];
    char *command;

    (void)argv;
    (void)env;

    /* strtok разбивает строку на части, используя пробелы и табы как разделители */
    command = strtok(line, " \t\r\n\a");
    
    /* Если после strtok ничего не осталось (строка была только из пробелов) */
    if (!command)
        return (0);

    child_pid = fork();
    if (child_pid == -1)
    {
        perror("Error");
        return (-1);
    }

    if (child_pid == 0)
    {
        args[0] = command; /* Теперь здесь чистая команда без пробелов */
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

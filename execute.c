#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * execute_command - выполняет команду с аргументами
 * @line: введённая строка пользователем
 * @env: массив переменных окружения
 */
void execute_command(char *line, char **env)
{
    char *args[100]; /* массив аргументов */
    int i = 0;
    char *token;
    pid_t pid;
    int status;

    /* Разделяем строку на токены по пробелам */
    token = strtok(line, " \t\n");
    while (token != NULL)
    {
        args[i++] = token;
        token = strtok(NULL, " \t\n");
    }
    args[i] = NULL; /* последний элемент должен быть NULL для execve */

    if (i == 0)
        return; /* пустая строка — ничего не делаем */

    pid = fork();
    if (pid == 0)
    {
        /* дочерний процесс: выполняем команду */
        if (execve(args[0], args, env) == -1)
        {
            perror("./hsh");
            exit(EXIT_FAILURE);
        }
    }
    else if (pid > 0)
    {
        /* родительский процесс ждёт дочерний */
        waitpid(pid, &status, 0);
    }
    else
    {
        perror("fork");
    }
}

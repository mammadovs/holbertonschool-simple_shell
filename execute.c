#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * execute_command - запускает команду с аргументами
 * @line: введённая строка пользователем
 * @env: массив переменных окружения
 */
void execute_command(char *line, char **env)
{
    char *args[100];  // Массив для аргументов
    int i = 0;
    char *token;
    pid_t pid;
    int status;

    // Токенизация строки по пробелам
    token = strtok(line, " \t\n");
    while (token != NULL)
    {
        args[i++] = token;
        token = strtok(NULL, " \t\n");
    }
    args[i] = NULL; // последний элемент должен быть NULL

    if (i == 0)
        return; // если строка пустая, ничего не делаем

    pid = fork();
    if (pid == 0)
    {
        // Дочерний процесс: выполняем команду
        if (execve(args[0], args, env) == -1)
        {
            perror("./hsh");
            exit(EXIT_FAILURE);
        }
    }
    else if (pid > 0)
    {
        // Родительский процесс: ждём завершения дочернего
        waitpid(pid, &status, 0);
    }
    else
    {
        perror("fork");
    }
}

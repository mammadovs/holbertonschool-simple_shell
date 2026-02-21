#include "shell.h"

/**
 * execute_command - минимальная реализация, чтобы компилировалось
 * @command: команда для выполнения
 * @argv: аргумент (по хэдеру)
 * @env: аргумент (по хэдеру)
 *
 * Return: всегда 0
 */
int execute_command(char *command, char argv, char env)
{
    (void)command;
    (void)argv;
    (void)env;

    return 0;
}

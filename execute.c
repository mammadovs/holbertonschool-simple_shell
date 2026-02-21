#include "shell.h"

/**
 * execute_command - executes a command
 * @command: command string
 * @argv: argument vector
 * @env: environment variables
 *
 * Return: 0 on success
 */
int execute_command(char *command, char **argv, char **env)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == -1)
	{
		perror(argv[0]);
		return (-1);
	}

	if (pid == 0)
	{
		if (execve(command, (char *[]){command, NULL}, env) == -1)
		{
			print_error(argv[0], command);
			exit(127);
		}
	}
	else
		wait(&status);

	return (0);
}

/**
 * print_error - prints error message
 * @shell_name: shell name
 * @command: command not found
 */
void print_error(char *shell_name, char *command)
{
	write(STDERR_FILENO, shell_name, strlen(shell_name));
	write(STDERR_FILENO, ": 1: ", 4);
	write(STDERR_FILENO, command, strlen(command));
	write(STDERR_FILENO, ": not found\n", 12);
}

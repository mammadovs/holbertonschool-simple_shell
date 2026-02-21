#include "shell.h"

/**
 * handle_builtins - checks and executes built-in commands
 * @args: array of arguments
 * @line: string to free on exit
 * @st: current exit status
 * Return: 1 if builtin found, 0 otherwise
 */
int handle_builtins(char **args, char *line, int st)
{
	int i;

	if (strcmp(args[0], "exit") == 0)
	{
		free(line);
		exit(st);
	}
	if (strcmp(args[0], "env") == 0)
	{
		for (i = 0; environ[i]; i++)
		{
			write(1, environ[i], strlen(environ[i]));
			write(1, "\n", 1);
		}
		return (1);
	}
	return (0);
}

/**
 * main - entry point for simple shell
 * Return: exit status
 */
int main(void)
{
	char *line, *args[32];
	int i, status = 0;

	while (1)
	{
		if (isatty(0))
			write(1, "$ ", 2);
		line = read_line();
		if (!line)
			break;
		i = 0;
		args[i] = strtok(line, " \t\r\n\a");
		while (args[i] && i < 31)
			args[++i] = strtok(NULL, " \t\r\n\a");
		if (args[0])
		{
			if (handle_builtins(args, line, status))
				status = 0;
			else
				status = execute_command(args);
		}
		free(line);
		if (!isatty(0) && status == 127)
			exit(127);
	}
	return (status);
}

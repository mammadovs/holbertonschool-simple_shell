#include "shell.h"

/**
 * main - основной цикл шелла
 * Return: статус последнего процесса
 */
int main(void)
{
	char *line;
	char *args[32];
	int i, status = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);

		line = read_line();
		if (!line)
			break;

		i = 0;
		args[i] = strtok(line, " \t\r\n\a");
		while (args[i] != NULL && i < 31)
			args[++i] = strtok(NULL, " \t\r\n\a");

		if (args[0] != NULL)
		{
			if (strcmp(args[0], "exit") == 0)
			{
				free(line);
				exit(status);
			}
			if (strcmp(args[0], "env") == 0)
			{
				for (i = 0; environ[i]; i++)
				{
					write(STDOUT_FILENO, environ[i], strlen(environ[i]));
					write(STDOUT_FILENO, "\n", 1);
				}
				status = 0;
			}
			else
				status = execute_command(args);
		}
		free(line);
		if (!isatty(STDIN_FILENO) && status == 127)
			exit(127);
	}
	return (status);
}

#include "shell.h"

/**
 * main - Entry point for simple shell
 * @argc: argument count (unused)
 * @argv: argument vector
 * @env: environment variables
 *
 * Return: 0 always
 */
int main(int argc, char **argv, char **env)
{
	char *line;
	(void)argc;

	while (1)
	{
		/* Показ prompt только если интерактивный терминал */
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

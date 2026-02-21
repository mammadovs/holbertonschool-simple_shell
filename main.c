#include "shell.h"

/**
 * main - Entry point for simple shell
 * @argc: argument count
 * @argv: argument vector
 * @env: environment variables
 *
 * Return: Always 0
 */
int main(int argc, char **argv, char **env)
{
	char *line;
	(void)argc;

	while (1)
	{
		display_prompt();
		line = read_line();

		if (!line)
		{
			write(STDOUT_FILENO, "\n", 1);
			exit(0);
		}

		if (line[0] != '\0')
			execute_command(line, argv, env);

		free(line);
	}

	return (0);
}

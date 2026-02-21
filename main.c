#include "shell.h"
#include <stdlib.h>
#include <unistd.h>

/**
 * main - вход в simple shell
 * @argc: количество аргументов (не используется)
 * @argv: вектор аргументов
 * @env: переменные окружения
 *
 * Return: 0 всегда
 */
int main(int argc, char **argv, char **env)
{
	char *line;
	(void)argc;

	while (1)
	{
		/* отображаем prompt только если интерактивный терминал */
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

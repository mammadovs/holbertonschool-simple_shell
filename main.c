#include "shell.h"

int main(void)
{
	char *line;
	char *args[32];
	int i, status = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			display_prompt();

		line = read_line();
		if (!line)
			break; /* EOF / Ctrl+D */

		if (strcmp(line, "exit") == 0)
		{
			free(line);
			exit(status); /* Выходим с последним статусом */
		}

		i = 0;
		args[i] = strtok(line, " \t\r\n\a");
		while (args[i] != NULL && i < 31)
			args[++i] = strtok(NULL, " \t\r\n\a");

		if (args[0] != NULL)
		{
			status = execute_command(args);
		}

		free(line);
		
		/* Если не интерактивный режим и команда не найдена, выходим сразу */
		if (!isatty(STDIN_FILENO) && status == 127)
			exit(127);
	}
	return (status);
}

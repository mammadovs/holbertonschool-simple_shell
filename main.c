#include "shell.h"

/**
 * main - точка входа в простой шелл
 * Return: статус последнего выполненного процесса
 */
int main(void)
{
	char *line;
	char *args[32];
	int i, status = 0;

	while (1)
	{
		/* Выводим промпт только в интерактивном режиме */
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, "$ ", 2);
		}

		line = read_line();
		if (!line) /* Обработка EOF (Ctrl+D) */
			break;

		/* Встроенная команда exit */
		if (strcmp(line, "exit") == 0)
		{
			free(line);
			exit(status);
		}

		/* Разбиваем строку на аргументы */
		i = 0;
		args[i] = strtok(line, " \t\r\n\a");
		while (args[i] != NULL && i < 31)
		{
			i++;
			args[i] = strtok(NULL, " \t\r\n\a");
		}

		/* Выполняем команду, если она введена */
		if (args[0] != NULL)
		{
			status = execute_command(args);
		}

		free(line);

		/* Если не интерактивный режим и команда не найдена, выходим с 127 */
		if (!isatty(STDIN_FILENO) && status == 127)
			exit(127);
	}
	return (status);
}

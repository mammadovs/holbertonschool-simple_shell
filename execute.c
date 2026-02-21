#include "shell.h"

/**
 * _which - ищет команду в директориях PATH
 * @command: имя команды (например, "ls")
 * Return: полный путь к команде или NULL
 */
char *_which(char *command)
{
	char *path, *path_copy, *token, *full_path;
	struct stat st;
	int i;

	/* Если в команде уже есть путь (начинается с / или .) */
	if (command[0] == '/' || command[0] == '.')
	{
		if (stat(command, &st) == 0)
			return (strdup(command));
		return (NULL);
	}
	/* Ищем строку PATH в окружении */
	path = NULL;
	for (i = 0; environ[i]; i++)
	{
		if (strncmp(environ[i], "PATH=", 5) == 0)
		{
			path = environ[i] + 5;
			break;
		}
	}
	if (!path)
		return (NULL);
	path_copy = strdup(path);
	token = strtok(path_copy, ":");
	while (token)
	{
		full_path = malloc(strlen(token) + strlen(command) + 2);
		strcpy(full_path, token);
		strcat(full_path, "/");
		strcat(full_path, command);
		if (stat(full_path, &st) == 0)
		{
			free(path_copy);
			return (full_path);
		}
		free(full_path);
		token = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}

/**
 * execute_command - парсит строку и запускает команду
 */
int execute_command(char *line, char **argv, char **env)
{
	char *args[32], *full_path;
	pid_t child_pid;
	int i = 0;
	(void)argv; (void)env;

	args[i] = strtok(line, " \t\r\n\a");
	while (args[i] && i < 31)
		args[++i] = strtok(NULL, " \t\r\n\a");
	if (!args[0])
		return (0);

	full_path = _which(args[0]);
	if (!full_path)
	{
		perror("./hsh");
		return (1);
	}

	child_pid = fork();
	if (child_pid == 0)
	{
		if (execve(full_path, args, environ) == -1)
		{
			perror("./hsh");
			free(full_path);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
		free(full_path);
	}
	return (0);
}

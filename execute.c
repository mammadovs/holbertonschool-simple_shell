#include "shell.h"

/**
 * _which - ищет команду в PATH
 * @command: имя команды
 * Return: полный путь или NULL
 */
char *_which(char *command)
{
	char *path, *path_copy, *token, *full_path;
	struct stat st;
	int i;

	if (command[0] == '/' || command[0] == '.')
	{
		if (stat(command, &st) == 0)
			return (strdup(command));
		return (NULL);
	}

	path = NULL;
	for (i = 0; environ[i]; i++)
	{
		if (strncmp(environ[i], "PATH=", 5) == 0)
		{
			path = environ[i] + 5;
			break;
		}
	}
	if (!path || !*path)
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
 * execute_command - выполняет команду с защитой от лишнего форка
 * @args: массив аргументов
 * Return: статус выхода
 */
int execute_command(char **args)
{
	char *full_path;
	pid_t child_pid;
	int status = 0;

	full_path = _which(args[0]);
	if (!full_path)
	{
		fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
		return (127);
	}

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error");
		free(full_path);
		return (1);
	}

	if (child_pid == 0)
	{
		if (execve(full_path, args, environ) == -1)
		{
			perror("./hsh");
			free(full_path);
			exit(127);
		}
	}
	else
	{
		wait(&status);
		free(full_path);
		if (WIFEXITED(status))
			status = WEXITSTATUS(status);
	}
	return (status);
}

#include "shell.h"

/**
 * _which - locates a command in PATH
 * @cmd: command name
 * Return: full path or NULL if not found
 */
char *_which(char *cmd)
{
	char *path = NULL, *tmp, *token, *full;
	struct stat st;
	int i;

	if (cmd[0] == '/' || cmd[0] == '.')
		return (stat(cmd, &st) == 0 ? strdup(cmd) : NULL);
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
	tmp = strdup(path);
	token = strtok(tmp, ":");
	while (token)
	{
		full = malloc(strlen(token) + strlen(cmd) + 2);
		sprintf(full, "%s/%s", token, cmd);
		if (stat(full, &st) == 0)
		{
			free(tmp);
			return (full);
		}
		free(full);
		token = strtok(NULL, ":");
	}
	free(tmp);
	return (NULL);
}

/**
 * execute_command - forks and executes a command
 * @args: arguments array
 * Return: exit status of the command
 */
int execute_command(char **args)
{
	char *path;
	pid_t pid;
	int status = 0;

	path = _which(args[0]);
	if (!path)
	{
		fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
		return (127);
	}
	pid = fork();
	if (pid == 0)
	{
		if (execve(path, args, environ) == -1)
			exit(127);
	}
	else
	{
		wait(&status);
		free(path);
		if (WIFEXITED(status))
			return (WEXITSTATUS(status));
	}
	return (0);
}

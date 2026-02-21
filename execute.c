#include "shell.h"

char *_which(char *cmd)
{
	char *path, *tmp, *token, *full;
	struct stat st;
	int i;

	if (cmd[0] == '/' || cmd[0] == '.')
	{
		if (stat(cmd, &st) == 0)
			return (strdup(cmd));
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

	tmp = strdup(path);
	token = strtok(tmp, ":");
	while (token)
	{
		full = malloc(strlen(token) + strlen(cmd) + 2);
		strcpy(full, token);
		strcat(full, "/");
		strcat(full, cmd);

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

int execute_command(char **args)
{
	char *path;
	pid_t pid;
	int status = 0;

	path = _which(args[0]);
	if (path == NULL)
	{
		fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
		return (127);
	}

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		free(path);
		return (1);
	}
	if (pid == 0)
	{
		if (execve(path, args, environ) == -1)
		{
			perror("execve");
			free(path);
			exit(127);
		}
	}
	else
	{
		wait(&status);
		free(path);
		if (WIFEXITED(status))
			status = WEXITSTATUS(status);
	}
	return (status);
}

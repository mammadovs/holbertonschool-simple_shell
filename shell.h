#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

/* Function prototypes */
char *read_line(void);
int execute_command(char **args);
char *_which(char *cmd);
int handle_builtins(char **args, char *line, int st);

#endif

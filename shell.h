#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/* Глобальная переменная окружения */
extern char **environ;

void display_prompt(void);
char *read_line(void);
int execute_command(char *line, char **argv, char **env);
char *_which(char *command);

#endif

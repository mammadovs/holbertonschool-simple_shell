#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/* Внешняя переменная окружения */
extern char **environ;

/* Прототипы функций */
char *read_line(void);
int execute_command(char **args);
char *_which(char *command);

#endif

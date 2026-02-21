#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

void display_prompt(void);
char *read_line(void);
int execute_command(char *command, char **argv, char **env);
void print_error(char *shell_name, char *command);

#endif

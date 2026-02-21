#ifndef SHELL_H
#define SHELL_H

int execute_command(char *command, char argv, char env);
char *read_line(void);
void display_prompt(void);

#endif /* SHELL_H */

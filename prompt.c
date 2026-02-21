#include "shell.h"

/**
 * display_prompt - prints shell prompt
 */
void display_prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
}

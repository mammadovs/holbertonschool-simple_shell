#include "shell.h"

/**
 * display_prompt - prints $ prompt if in interactive mode
 */
void display_prompt(void)
{
	/* Check if stdin is a terminal */
	if (isatty(0))
		write(1, "$ ", 2);
}

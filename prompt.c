#include "shell.h"

/**
 * display_prompt - рисует знак доллара для ввода
 * Мы проверяем isatty, чтобы не спамить промптом в скриптах
 */
void display_prompt(void)
{
	/* 0 - это stdin, 1 - это stdout. Так короче и понятнее */
	if (isatty(0))
		write(1, "$ ", 2);
}

#include <unistd.h>

/**
 * display_prompt - выводит приглашение $ если stdin является терминалом
 */
void display_prompt(void)
{
    if (isatty(STDIN_FILENO))
        write(STDOUT_FILENO, "$ ", 2);
}

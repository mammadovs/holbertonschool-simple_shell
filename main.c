#include "shell.h"
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    char *line;

    while (1)
    {
        /* Выводим $ только если ввод идет из терминала */
        if (isatty(STDIN_FILENO))
            display_prompt();

        line = read_line();
        
        /* Если получили EOF (Ctrl+D или конец pipe) */
        if (!line)
        {
            if (isatty(STDIN_FILENO))
                write(STDOUT_FILENO, "\n", 1);
            exit(0);
        }

        /* Вызываем функцию исполнения. Передаем NULL для argv и env */
        execute_command(line, NULL, NULL);
        
        free(line);
    }

    return (0);
}

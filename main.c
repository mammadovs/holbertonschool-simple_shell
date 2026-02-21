#include "shell.h"
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    char *line;

    while (1)
    {
        if (isatty(STDIN_FILENO))
            display_prompt();

        line = read_line();
        if (!line)
        {
            if (isatty(STDIN_FILENO))
                write(STDOUT_FILENO, "\n", 1);
            exit(0);
        }

        execute_command(line, 0, 0);
        free(line);
    }

    return 0;
}

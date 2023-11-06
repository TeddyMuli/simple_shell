#include "main.h"

/**
 * simple_shell - command line interpreter
 * 
 * Return: void
*/
void simple_shell(void) {
    char *line;
    char **args;
    int status;

    do {
        printf("simple_shell $ ");
        line = read_line();
        args = split_line(line);
        status = execute_cmd(args);

        free(line);
        free(args);
    } while (status);
}


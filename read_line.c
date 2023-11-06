#include "main.h"

/**
 * read_line - function that reads input from user
 * 
 * Return: The line
*/

char *read_line(void) {
    char *line = NULL;
    size_t bufsize = 0;

    if (getline(&line, &bufsize, stdin) == -1)
    {
        if (feof(stdin)) {
            free(line);
            exit(EXIT_SUCCESS);
        }
        else {
            free(line);
            perror("Error while reading line");
            exit(EXIT_FAILURE);
        }
    }
    return (line);
}

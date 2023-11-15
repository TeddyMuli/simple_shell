#include "main.h"

/**
 * split_line - Function that splits command in the terminal
 * 
 * Return: Return pointer to the new array
*/

char **split_line(char *line)
{
    int bufsize = 64;
    int i = 0;
    char **tokens = malloc(bufsize * sizeof(char *));
    char *token;

    if (!tokens)
    {
        fprintf(stderr, "allocation error\n");
        exit(EXIT_FAILURE);
    }
    token = strtok(line, TOKEN_DELIMITER);
    while (token != NULL)
    {
        if (token[0] == '#')
        {
            break;
        }
        tokens[i] = token;
        i++;
        if (i >= bufsize)
        {
            bufsize += bufsize;
            tokens = realloc(tokens, bufsize * sizeof(char *));
            if (!tokens)
            {
                fprintf(stderr, "allocation error\n");
                exit(EXIT_FAILURE);
            }
        }
        token = strtok(NULL, TOKEN_DELIMITER);
    }
    tokens[i] = NULL;
    return (tokens);
    
}


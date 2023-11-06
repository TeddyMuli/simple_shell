#include "main.h"

/**
 * my_cd - changes working directory
 * @args: target directory
 * 
 * Return: 1 if success, 0 otherwise
*/
int my_cd(char **args)
{
    if (args[1] == NULL)
    {
        fprintf(stderr, "expected argument\n");
    }
    else
    {
        if (chdir(args[1]) != 0)
        {
            perror("Error!!");
        }
    }
    return (-1);
}


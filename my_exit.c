#include "main.h"

/**
 * my_exit - exit the shell
 * 
 * Return: 0 to kill process
*/
int my_exit(char **args)
{
    if (args[1])
    {
        return (atoi(args[1]));
    }
    else {
        return (0);
    }
}

#include "main.h"

/**
 * my_env - prints environment variables
 * @args: arguments
 * 
 * Return: 1 on success
*/

int my_env(char **args)
{
    int i = 0;
    (void)(**args);

    while (environ[i])
    {
        write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
    }
    return (-1);
}


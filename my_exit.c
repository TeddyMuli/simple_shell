#include "main.h"

/**
 * my_exit - couses normal process termination
 * @args: empty args
 *
 * Return: 0 to terminate the process
 */
int my_exit(char **args)
{
	if (args[1])
	{
		return (atoi(args[1]));
	}
	else
	{
		return (0);
	}
}

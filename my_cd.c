#include "main.h"

/**
 * my_cd - changes the working dir of the current shell executon env
 * @args: target directory
 *
 * Return: 1 one success, 0 otherwise.
 */
int my_cd(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("error in my_cd.c: changing dir\n");
		}
	}
	return (-1);
}
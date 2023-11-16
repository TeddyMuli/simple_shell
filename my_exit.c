#include "main.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>


/**
 * my_exit - This causes normal process termination.
 * @args: arguments
 *
 * Return: exit code to terminate the process, or -1 on error
 */
int my_exit(char **args)
{
if (args[1] != NULL)
{
char *endptr;
long exit_code = strtol(args[1], &endptr, 10);
if (*endptr != '\0' || exit_code < INT_MIN || exit_code > INT_MAX)
{
fprintf(stderr, "Invalid exit code\n");
return (-1);
}
return ((int)exit_code);
}
else
{
return (0);
}
}


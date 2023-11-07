#include "main.h"

/**
 * my_help - print help
 * @args: arguments
 *
 * Return: 1 on success, 0 otherwise
 */
int my_help(char **args)
{
	char *builtin_function_list[] = {
		"cd",
		"env",
		"help",
		"exit"
	};
	int i = 0;
	(void)(**args);

	printf("\n---help simple_shell---\n");
	printf("Type a command and its arguments, then hit enter\n");
	printf("Built-in commands:\n");
	for (; i < num_builtin(); i++)
	{
		printf("  -> %s\n", builtin_function_list[i]);
	}
	printf("Use the man command for information on other programs.\n\n");
	return (-1);
}

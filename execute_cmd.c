#include "main.h"

/**
 * num_builtin - return the number of builtin functions
 *
 * Return: number of builtin functions
 */
int num_builtin(void)
{
	char *builtin_function_list[] = {
		"cd",
		"env",
		"help",
		"exit"
	};

	return (sizeof(builtin_function_list) / (sizeof(char *)));
}

/**
 * execute_cmd - map if command is a builtin or a process
 * @args: command and its flags
 *
 * Return: 1 on sucess, 0 otherwise
 */
int execute_cmd(char **args)
{
	char *builtin_function_list[] = {
		"cd",
		"env",
		"help",
		"exit"
	};
	int (*builtin_functions[])(char **) = {
		&my_cd,
		&my_env,
		&my_help,
		&my_exit
	};
	int i = 0;

	if (args[0] == NULL)
	{
		return (-1);
	}
	for (; i < num_builtin(); i++)
	{
		if (strcmp(args[0], builtin_function_list[i]) == 0)
		{
			return ((*builtin_functions[i])(args));
		}
	}
	return (new_process(args));
}

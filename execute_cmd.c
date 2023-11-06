#include "main.h"

/**
 * nums_builtin - function with builtin commands
 * 
 * Return: number of builtin commands
*/
int num_builtin(void)
{
    char *builtin_list[] = {
        "cd",
        "env",
        "help",
        "exit"
    };

    return (sizeof(builtin_list) / (sizeof(char *)));
}

/**
 * execute_cmd - execute entered commands
 * @args: command
 * 
 * Return: 1 on success, 0 otherwise
*/
int execute_cmd(char **args)
{
    char *builtin_list[] = {
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
    for (i = 0; i < num_builtin(); i++)
    {
        if (strcmp(args[0], builtin_list[i]) == 0)
        {
            return ((*builtin_functions[i])(args));
        }
    }
    return (new_process(args));
}

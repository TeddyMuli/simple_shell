#include "main.h"

/**
 * simple_shell - command line interpreter
<<<<<<< HEAD
 * 
 * Return: void
*/
void simple_shell(void) {
    char *line;
    char **args;
    int status;

    do {
        printf("simple_shell $ ");
        line = read_line();
        args = split_line(line);
        status = execute_cmd(args);

        free(line);
        free(args);
    } while (status);
}

=======
 *
 * Return: void
 */
void simple_shell(void)
{
	char *line;
	char **args;
	int status = -1;

	do {
		printf("simple_shell $ ");
		line = read_line(); 
		args = parse_line(line); 
		status = execute_cmd(args);

		free(line);
		free(args);
		if (status >= 0)
		{
			exit(status);
		}
	} while (status == -1);
}
>>>>>>> 61128c8875b568e9a306269e345e84aa7d696339

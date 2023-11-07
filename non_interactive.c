#include "main.h"

/**
 * non_interactive - non interactive command line interpreter
 *
 * Return: void
 */
void non_interactive(void)
{
	char *line;
	char **args;
	int status = -1;

	do {
		line = read_stream();
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

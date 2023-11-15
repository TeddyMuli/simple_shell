#include "main.h"

/**
 * read_line - Read a line from stdin.
 *
 * This function reads a line from the std input using getline
 * and dynamically allo'ts memory for the line content.
 *
 * Return: A pointer that points to a string with the line content.
 */
char *read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;

	if (getline(&line, &bufsize, stdin) == -1)
	{
		if (feof(stdin))
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		else
		{
			free(line);
			perror("error in read_line: getline");
			exit(EXIT_FAILURE);
		}
	}
	return (line);
}

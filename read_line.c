#include "main.h"

/**
 * read_line:This read a line from stdin
 *
 * Return: pointer that points to a str with the line content
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

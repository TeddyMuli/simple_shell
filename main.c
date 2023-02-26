#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "main.h"

int tsh_cd(char **args);
int tsh_help(char **args);
int tsh_exit(char **args);

char *builtin_str[] = {
	"cd",
	"help",
 	"exit"
};


int (*builtin_func[]) (char **) = {
	&tsh_cd,
	&tsh_help,
	&tsh_exit
};

/*
 * List of builtin commands, followed by
 *  their corresponding functions.
 */


int tsh_num_builtins(void)
{
       	return (sizeof(builtin_str) / sizeof(char *));
}

/*
 * Builtin function implementations.
*/
int tsh_cd(char **args)
{
	if (args[1] == NULL)
       	{
		fprintf(stderr, "tsh: expected argument to \"cd\"\n");
	}
	else 
	{
	if (chdir(args[1]) != 0)
       	{
		perror("tsh");
	}
	}
return (1);
}

int tsh_help(char **args)
{
	int i;
	printf("Type program names and arguments, and hit enter.\n");
	printf("The following are built in:\n");

for (i = 0; i < tsh_num_builtins(); i++)
{
	printf("  %s\n", builtin_str[i]);
}

printf("Use the man command for information on other programs.\n");
return (1);
}

int tsh_exit(char **args)
{
return (0);
}

int tsh_launch(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
	{
		perror("tsh");
	}
	exit(EXIT_FAILURE);
	}
       	else if (pid < 0)
	{
		perror("tsh");
	} else
	{
		do {
 		waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}

int tsh_execute(char **args)
{
	int i;

	if (args[0] == NULL)
	{
    // An empty command was entered.
	return (1);
	}

for (i = 0; i < tsh_num_builtins(); i++)
{
	if (strcmp(args[0], builtin_str[i]) == 0)
       {
	return (*builtin_func[i])(args);
       }
}

return tsh_launch(args);
}

#define BUFSIZE 1024
char *tsh_read_line(void)
{
	int position = 0;
	int bufsize = BUFSIZE;
	char c;
	char *buffer = malloc(sizeof(char) * bufsize);

	if (!buffer)
	{
		printf("tsh: reallocation error\n");
		exit(EXIT_FAILURE);
	}

while (1)
{
	c = getchar();

	if (c == EOF)
       	{
	exit(EXIT_SUCCESS);
	}
       	else if (c == '\n')
	{
	buffer[position] = '\0';
	return (buffer);
	} else
	{
	buffer[position] = c;
	}
	position++;

	if (position >= bufsize)
	{
		bufsize += BUFSIZE;
		buffer = realloc(buffer,bufsize);
		if (!buffer)
		{
			printf("tsh: reallocation error\n");
			exit(EXIT_FAILURE);
		}
	} 
}
}

#define TSH_TOK_BUFSIZE 64
#define TSH_TOK_DELIM " \t\r\n\a"
char **tsh_split_line(char *line)
{
	int bufsize = TSH_TOK_BUFSIZE, position = 0;
	char **tokens = malloc(bufsize * sizeof(char*));
	char *token ,**tokens_backup;

	if (!tokens) {
	fprintf(stderr, "tsh: allocation error\n");
	exit(EXIT_FAILURE);
	}

	token = strtok(line, TSH_TOK_DELIM);
	while (token != NULL)
       	{
	tokens[position] = token;
	position++;

	if (position >= bufsize)
	{
		bufsize += TSH_TOK_BUFSIZE;
		tokens_backup = tokens;
		tokens = realloc(tokens, bufsize * sizeof(char*));
	if (!tokens)
	{
	free(tokens_backup);
	fprintf(stderr, "tsh: allocation error\n");
	exit(EXIT_FAILURE);
	}
	}
	token = strtok(NULL, TSH_TOK_DELIM);
	}
	tokens[position] = NULL;
	return (tokens);
}

void tsh_loop(void)
{
	char *line;
	char **args;
	int status;

	do
	{
		printf("root@teddy.user # ");
		line = tsh_read_line();
		args = tsh_split_line(line);
 		status = tsh_execute(args);

		free (line);
		free (args);
	} while (status);
}

int main(int argc, char *argv)
{
	tsh_loop();
	return (EXIT_SUCCESS);
}

#include "main.h"

/**
 * new_process -This create a new process
 * @args: array of strings that contains the cmd and its flags
 *
 * Return: 1 if success, 0 otherwise.
 */
int new_process(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid ==  0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("error in new_process: child process");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("error in new_process: forking");
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (-1);
}


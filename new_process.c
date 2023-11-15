#include "main.h"

/**
 * new_process - function that creates a new process
 * 
 * Return: 1 if succeeds, 0 otherwise
*/
int new_process(char **args)
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0)
    {
        if (execvp(args[0], args) == -1)
        {
            perror("Error in new_process");
        }
        exit(EXIT_FAILURE);
    }
    else if (pid < 0)
    {
        perror("Error in new process");
    }
    else
    {
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
    return (-1);
}


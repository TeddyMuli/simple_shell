#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>


#define TOKEN_DELIMITER "\t\r\n\a\""
/** main.c */
void simple_shell(void);

/** simple_shell.c */
char *read_line(void);
char **split_line(char *line);
int execute_cmd(char **args);

/** execute_cmd.c */
int num_builtin(void);
int new_process(char **args);

extern char **environ;

int my_help(char **args);
int my_cd(char **args);
int my_env(char **args);
int my_exit(char **args);

#endif

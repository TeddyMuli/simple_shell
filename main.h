#ifndef MAIN_H
#define MAIN_H

/* LIBRARIES */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

/* MACROS */
#define TOK_DELIMITER " \t\r\n\a\""
extern char **environ;

/* PROTOTYPES */
/*---main.c---*/
void simple_shell(void);
void non_interactive(void);

/*---shell_interactive---*/
char *read_line(void);
char **parse_line(char *line);
int execute_cmd(char **args);

/*---shell_non_interactive---*/
char *read_stream(void);

/*---execute_args---*/
int new_process(char **args);
int num_builtin(void);

/*---builtin---*/
int my_cd(char **args);
int my_exit(char **args);
int my_env(char **args);
int my_help(char **args);

#endif

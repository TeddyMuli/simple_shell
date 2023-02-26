#ifndef MAIN
#define MAIN
#include <stddef.h>
void tsh_loop(void);
char *tsh_read_line(void);
char **tsh_split_line(char *line);
int tsh_launch(char **args);
int tsh_cd(char **args);
int tsh_help(void);
int tsh_exit(void);
int tsh_num_builtins(void);
int tsh_cd(char **args);
int tsh_help(char **args);
int tsh_exit(char **args);
int tsh_execute(char **args);


#endif

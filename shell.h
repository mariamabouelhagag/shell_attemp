#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <wait.h>

char* cmd_read();
char **split_cmd();
char **token_save();
void free_tokens(char **tokens);
void execute_builtin(char **tokens);
char *get_path(char *cmd);
char **execute_tokens();
int count_tokens();
void add_token(char* token);


#endif

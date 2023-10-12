#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 100

void display_prompt();
void execute_command(char **cmd, char **path_list, int num_paths);
char **parse_input(char *input);
void free_command(char **cmd);


#endif

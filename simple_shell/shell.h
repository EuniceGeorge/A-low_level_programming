#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>

#define MAX_INPUT_LENGTH 100

extern char **environ;

void display_prompt();
void execute_command(char **cmd, char **path_list, int num_paths);
char **parse_input(char *input);
void free_command(char **cmd);
void handle_exit_command(char **cmd);
int is_builtin_command(char *cmd);
void print_environment();
char *check_command_exists(char *cmd);
char *filecheck (char *str);
#endif

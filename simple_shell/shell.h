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

void display_prompt(void);
/*void execute_command(char **cmd, char **path_list, int num_paths);*/
void execute_command( char *full_path, char **cmd);
char **parse_input(char *input);
void free_command(char **cmd);
void handle_exit_command(char **cmd);
int is_builtin_command(char *cmd);
void print_environment(void);
char *filecheck (char *str);
char *find_command_path(const char *cmd, char **path_list, int num_paths);

int set_environment_variable(char *variable, char *value);
int unset_environment_variable(char *variable);
#endif

#include "shell.h"

/**
 * execute_command - Attempts to execute the given command with arguments using execve.
 *
 * @param cmd: The command and its arguments as an array.
 * @param path_list: The list of directories to search for the command.
 * @param num_paths: The number of directories in path_list.
 */

void execute_command(char **cmd, char **path_list, int num_paths) {
    char *full_path = NULL;
    int command_found = 0;
    int i = 0;
    pid_t pid;

    while (i < num_paths && !command_found) {
        full_path = malloc(strlen(path_list[i]) + strlen(cmd[0]) + 2);  
        if (!full_path) {
            perror("malloc");
            exit(EXIT_FAILURE);
        }

        sprintf(full_path, "%s/%s", path_list[i], cmd[0]);

        if (access(full_path, X_OK) == 0) {
            command_found = 1;
        } else {
            free(full_path);
            i++;
        }
    }

    if (command_found) {
        pid = fork();
        if (pid == 0) {  
            if (execve(full_path, cmd, NULL) == -1) {
                perror("execve");
                free(full_path);
                exit(EXIT_FAILURE);
            }
        } else if (pid < 0) { 
            perror("fork");
            free(full_path);
            exit(EXIT_FAILURE);
        } else { 
            int status;
            waitpid(pid, &status, 0);
        }
        free(full_path);
    } else {
        printf("Command not found: %s\n", cmd[0]);
        exit(EXIT_FAILURE);
    }
}

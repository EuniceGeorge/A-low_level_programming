#include "shell.h"

/**
 * check_command_exists - Checks if the command exists in the PATH.
 * If it exists, returns the full path of the command; otherwise, returns NULL.
 *
 * @param cmd: The command to check.
 * @return The full path of the command if it exists, NULL otherwise.
 */

char *check_command_exists(char *cmd){
    char *path = getenv("PATH");
    char *token = strtok(path, ":");

    while (token != NULL) {
        char path_with_command[MAX_INPUT_LENGTH];
        snprintf(path_with_command, sizeof(path_with_command), "%s/%s", token, cmd);

        if (access(path_with_command, X_OK) == 0) {
            return strdup(path_with_command);
        }

        token = strtok(NULL, ":");
    }

    return NULL;  
}

#include "shell.h"

/**
 * print_environment - Prints the current environment variables.
 */

void handle_env_command() {
    char **env = environ;
       while (*env) {
        printf("%s\n", *env);
        env++;
    }
}

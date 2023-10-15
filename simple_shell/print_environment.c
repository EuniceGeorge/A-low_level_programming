#include "shell.h"

/**
 * print_environment - Prints the current environment variables.
 */
void print_environment() {
    char **env = environ;

    while (*env) {
        printf("%s\n", *env);
        env++;
    }
}

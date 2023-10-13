#include "shell.h"

void handle_env_command() {
    char **env = environ;
       while (*env) {
        printf("%s\n", *env);
        env++;
    }
}

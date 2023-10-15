#include "shell.h"

/**
 * parse_input - Tokenizes the input line to separate the command and its arguments.
 *
 * @param input: The input line.
 * @return An array of strings containing the command and its arguments.
 */
char **parse_input(char *input) {
    char *token;
    char **cmd = malloc(sizeof(char *) * (MAX_INPUT_LENGTH / 2 + 1));
    int i = 0;

    if (!cmd) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    token = strtok(input, " \t\n");
    while (token != NULL && i < (MAX_INPUT_LENGTH / 2)) {
        cmd[i] = strdup(token);
	if (!cmd[i]) {
            perror("strdup");
            exit(EXIT_FAILURE);
	}
        i++;
        token = strtok(NULL, " \t\n");
    }
    cmd[i] = NULL;

    return cmd;
}


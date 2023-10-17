#include "shell.h"

/**
 * main - Entry point for the simple_shell program.
 *
 * Return: Always 0 on success.
 */

int main(void) {
	char *input = NULL;
	size_t input_len = 0;
	char *path = getenv("PATH");
	char *token;
	char **cmd;
	char **path_list = NULL;
	int num_paths = 0;

	token = strtok(path, ":");

    while (token != NULL) {
        path_list = realloc(path_list, (num_paths + 1) * sizeof(char *));
        if (!path_list) {
            perror("realloc");
            exit(EXIT_FAILURE);
        }

        path_list[num_paths] = strdup(token);
        if (!path_list[num_paths]) {
            perror("strdup");
            exit(EXIT_FAILURE);
        }
        num_paths++;
        token = strtok(NULL, ":");
    }

    while (1) {
	    if (isatty(STDIN_FILENO))
	display_prompt();
	 if (getline(&input, &input_len, stdin) == -1) {
            printf("\n");
            free(input);
            break; 
        }

        input[strcspn(input, "\n")] = '\0';

	if (strcmp(input, "exit") == 0) {
            free(input);
            break;
        }
	if (strcmp(input, "env") == 0) {
		print_environment();
            free(input);
            continue;
        }
        cmd = parse_input(input);
	if (strcmp(cmd[0], "exit") == 0) {
		if (cmd[1] != NULL) {
              int status = atoi(cmd[1]);
            free_command(cmd);
	    exit(status);
            free(input);
	}
            break;
        } else {

      execute_command(cmd, path_list, num_paths);
	 free_command(cmd);
    }
    }

    return 0;
}

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
    char **path_list = NULL;
    int num_paths = 0;
    char **cmd;

    token = strtok(path, ":");
    while (token != NULL) {
        path_list = realloc(path_list, (num_paths + 1) * sizeof(char *));
        if (!path_list) {
            perror("realloc");
            exit(EXIT_FAILURE);
        }

        path_list[num_paths] = strdup(token);
        num_paths++;
        token = strtok(NULL, ":");
    }
    while (1) {
        display_prompt();

        if (getline(&input, &input_len, stdin) == -1) {
            printf("\n");
            free(input);

	    while (num_paths > 0) {
                free(path_list[num_paths - 1]);
                num_paths--;
            }
            free(path_list);

            break;

        }

        input[strcspn(input, "\n")] = '\0';

        cmd = parse_input(input);
	if (strcmp(cmd[0], "exit") == 0) {
	       	handle_exit_command(cmd);
	} else if (strcmp(cmd[0], "env") == 0) {
		handle_env_command();
	} else {
		execute_command(cmd, path_list, num_paths);

        free_command(cmd);
    }

    while (num_paths > 0) {
        free(path_list[num_paths - 1]);
        num_paths--;
    }
    free(path_list);
    }
    return 0;
}


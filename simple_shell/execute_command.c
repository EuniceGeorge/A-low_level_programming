#include "shell.h"

/**
 * execute_command - Attempts to execute the given command with arguments using execve.
 * @param cmd: The command and its arguments as an array.
 * @param path_list: The list of directories to search for the command.
 * @param num_paths: The number of directories in path_list.
 */
void execute_command(char **cmd, char **path_list, int num_paths) {
	char *full_path = NULL;
	int i = 0;
       int command_found = 0;

	while (!command_found && i < num_paths) {

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

	if (command_found && full_path) {
		pid_t child_pid = fork();
		if (child_pid == -1) {
			perror("fork");
			exit(EXIT_FAILURE);
		} else if (child_pid == 0) {

	if (execve(full_path, cmd, NULL) == -1) {
	       perror("execve");
	       exit(EXIT_FAILURE);
	    }
	  } else {
	/* Parent process*/
	  int status;
	  waitpid(child_pid, &status, 0);
	  }
	} else {
	/* Command not found in any directory or memory allocation failed*/
		if (!full_path) {
		       	printf("Memory allocation failed.\n");
		} else {
	printf("Command not found: %s\n", cmd[0]);
	}
	}
/*	if (full_path)	  */
         free(full_path);
}

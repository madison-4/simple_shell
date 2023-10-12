#include "main.h"

int executeFile(char **command)
{
	char *execPath;
	int waitStatus = 0, executeRV = 0;
	pid_t processID = 0;

	execPath = fullpath(command[0]);
	if (execPath == NULL)
	{
		fprintf(stderr, "./hsh: %s: not found\n", command[0]);
		return (EXIT_FAILURE);
	}
	processID = fork();

	if (processID == -1)
	{
		perror("Error Creating process");
		exit(EXIT_FAILURE); /* return with exit failure */
	}
	else if (processID == 0)
	{
		/* printf("Inside child process\n"); */
		/* printf("exexutable %s\n", execPath); */
		/* call execve */
		executeRV = execve(execPath, command, environ);
			/*calling execve with command array and global environ variable */
		if (executeRV == -1)
		{
			perror("Failed to execute program");
			free(execPath);
			return (EXIT_FAILURE);
		}
	}
	else
	{
		/* printf("Inside parent process\n"); */
		wait(&waitStatus);
	}
	free(execPath);
	return (EXIT_SUCCESS);
}

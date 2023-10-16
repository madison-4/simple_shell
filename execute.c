#include "main.h"

/**
 * executeFile - a function to execute a command
 * @command: input commands
 *
 * Return: Exit Status
 */

int executeFile(char **command)
{
	char *execPath;
	int waitStatus = 0, executeRV = 0;
	pid_t processID = 0;

	execPath = fullpath(command[0]);
	if (execPath == NULL)
	{
		fprintf(stderr, "./hsh: 1: %s: not found\n", command[0]);
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
		executeRV = execve(execPath, command, environ);
		if (executeRV == -1)
		{
			perror("Failed to execute program");
			free(execPath);
			return (EXIT_FAILURE);
		}
	}
	else
	{
		wait(&waitStatus);
	}
	free(execPath);
	return (EXIT_SUCCESS);
}

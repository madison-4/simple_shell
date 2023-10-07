#include "main.h"

int executeFile(char **command)
{
	int waitStatus = 0;
	pid_t processID = 0;

	processID = fork();

	if (processID == -1)
	{
		perror("Error Creating process");
		exit(EXIT_STATUS); /* return with exit failure */
	}
	else if (processID == 0)
	{
		printf("Inside child process\n");
		/* call execve */
	}
	else
	{
		printf("Inside parent process\n");
		wait(&waitStatus);
	}

	return (EXIT_SUCCESS);

}

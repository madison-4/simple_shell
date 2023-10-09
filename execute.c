#include "main.h"

int executeFile(char **command)
{
	int waitStatus = 0;
	pid_t processID = 0;

	processID = fork();

	if (processID == -1)
	{
		perror("Error Creating process");
		exit(EXIT_FAILURE); /* return with exit failure */
	}
	else if (processID == 0)
	{
		printf("Inside child process\n");
		/* call execve */
		execve(command[0], command, environ);
			/*calling execve with command array and global environ variable */
	}
	else
	{
		printf("Inside parent process\n");
		wait(&waitStatus);
	}

	return (EXIT_SUCCESS);

}

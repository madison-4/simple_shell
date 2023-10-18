#include "main.h"

/**
 * checkinbuilt - checks if a command is an inbuilt command
 * @string: custom array of strings
 * @inputString: command output
 *
 * Return: 1 if inbuilt or -1 if not inbuilt
 */

int checkinbuilt(char **string, char *inputString)
{
	if (cmpStr(string[0], "exit") == 0)
	{
		free(inputString);
		free(string[0]);
		free(string);
		exit(EXIT_SUCCESS);
	}
	else if (cmpStr(string[0], "env") == 0)
	{
		if (getpid() == 0)
			printenv();
		/* return (1); */
	}
	else
	{
		/* some other logic */
		return (1);
	}
	return (-1);
}

#include "main.h"

int checkinbuilt(char **string, char *inputString)
{
	if (strcmp(string[0], "exit") == 0)
	{
		free(inputString);
		free(string[0]);
		free(string);
		exit(EXIT_SUCCESS);
	}
	else if (strcmp(string[0], "env") == 0)
	{
		/* printenv();*/
		/* return (1); */
	}
	else
	{
		/* some other logic */

		/* EXIT_STATUS = EXIT_SUCCESS; */
		return (1);
	}
	return (-1);
}

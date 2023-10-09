#include "main.h"

int checkinbuilt(char *string)
{
	if (strcmp(string, "exit") == 0)
	{
		/* free(memory address) */
		exit(EXIT_SUCCESS);
	}
	else if (strcmp(string, "env") == 0)
	{
		/* printenv();*/
	}
	else
		/* some other logic */

	/* EXIT_STATUS = EXIT_SUCCESS; */
		return (0);
	return (0);
}

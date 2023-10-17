#include "main.h"

/**
 * printenv - prints environment variable
 */

void printenv(void)
{
	int i = 0;

	for (i = 0; environ[i] != NULL; i++)
	{
		write(1, environ[i], strLen(environ[i]));
		write(1, "\n", 1);
	}
}

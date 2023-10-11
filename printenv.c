#include "main.h"

void printenv(void)
{
	int i = 0;

	for (i = 0; environ[i] != NULL; i++)
	{
		write(1, environ[i], strlen(environ[i]));
		write(1, "\n", 1);
	}
}

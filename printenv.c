#include "main.h"
/**
 * printenv - print the environment variables
 * no aruments
 * Return: nothing
 */
void printenv(void)
{
	int i = 0;

	for (i = 0; environ[i] != NULL; i++)
	{
		write(1, environ[i], _strlen(environ[i]));
		write(1, "\n", 1);
	}
}

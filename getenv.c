#include "main.h"

/**
 * _getenv - gets the environment variable of a particular name
 * @name: of the environment variable to searh for
 *
 * Return: pointer to the environment variable
 */

char *_getenv(char *name)
{
	char *token;
	int i;
	char **ep = environ;

	for (i = 0; ep[i] != NULL; i++)
	{
		token = strtok(ep[i], "=");
		while (token)
		{
			if (cmpStr(token, name) == 0)
			{
				return (ep[i] + strLen(name) + 1);
			}
			token = strtok(NULL, "=");
		}
	}
	return (NULL);
}


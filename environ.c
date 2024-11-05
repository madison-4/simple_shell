#include "shell.h"
/**
 * _getenv - a function to get the value of an environment variable
 * It copies the functionality of the defauklt getenv function
 * @name: name of the environment variable
 * Return: value of the environment variable
 */
char *_getenv(char *name)
{
	int i, j, status;

	for (i = 0; environ[i]; i++)
	{
		status = 1;
		for (j = 0; environ[i][j] != '='; j++)
		{
			if (environ[i][j] != name[j])
			{
				status = 0;
				break;
			}
		}
		if (status)
			return (environ[i][j + 1]);
	}
	return (NULL);
}

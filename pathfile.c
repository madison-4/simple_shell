#include "main.h"

/**
 * fullpath - finds the fullpath to a command
 * @command_Idx: input command
 *
 * Return: Fullpath to a command
 */

char *fullpath(char *command_Idx)
{
	char *fullPath, *dupFilePath, *token;
	size_t len = 0;
	struct stat statbuf;
	char *filePath = getenv("PATH");

	if (command_Idx == NULL)
	{
		perror("NULL input received");
		return (NULL);
	}
	if (stat(command_Idx, &statbuf) == 0)
	{
		return (_strdup(command_Idx));
	}
	dupFilePath = _strdup(filePath);
	token = strtok(dupFilePath, ":");
	while (token != NULL)
	{
		len = strlen(command_Idx) + strlen(filePath) + 2;
		fullPath = malloc(len);
		if (fullPath == NULL)
			break;
		else if (fullPath != NULL)
		{
			strCopy(fullPath, token);
			strCat(fullPath, "/");
			strCat(fullPath, command_Idx);
			if (stat(fullPath, &statbuf) == 0)
			{
				free(dupFilePath);
				return (fullPath);
				printf("Full :%s\n", fullPath);
			}
		}
		free(fullPath);
		token = strtok(NULL, ":");
	}
	free(dupFilePath);
	return (NULL);
}

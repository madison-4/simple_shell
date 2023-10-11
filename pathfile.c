#include "main.h"

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
		return (strdup(command_Idx));
	}
	dupFilePath = strdup(filePath);
	token = strtok(dupFilePath, ":");
	while (token != NULL)
	{
		len = strlen(command_Idx) + strlen(filePath) + 2;
		fullPath = malloc(len);
		if (fullPath == NULL)
			break;
		else if (fullPath != NULL)
		{
			strcpy(fullPath, token);
			strcat(fullPath, "/");
			strcat(fullPath, command_Idx);
			if (stat(fullPath, &statbuf) == 0)
			{
				free(dupFilePath);
				return (fullPath);
			}
		}
		free(fullPath);
		token = strtok(NULL, ":");
	}
	free(dupFilePath);
	return (NULL);
}

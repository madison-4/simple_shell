#include "main.h"


static char *token;
char *mystrtok(char *str, const char *delim)
{
	char *index = NULL;

	if (str != NULL)
		token = str;

	if (token == NULL)
		return (NULL);

	index = token;

	while (*token != delim && *token != '\0')
		token++;

	if (*token)
	{
		*token = '\0';
		token++;
	}
	token = NULL;

	return (index);
}

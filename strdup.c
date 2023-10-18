#include "main.h"

/**
 * _strdup - duplicates a string into newly allocated array
 *
 * @str: string to duplicate
 *
 * Return: pointer to new string
 */

char *_strdup(char *str)
{
	int i, j, len = 0;
	char *ptr;

	if (str == NULL)
		return (NULL);

	for (i = 0; str[i]; i++)
		len++;

	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);

	for (j = 0; j < len; j++)
		ptr[j] = str[j];
	ptr[len] = '\0';

	return (ptr);
}


#include "shell.h"

/**
 * _strlen - a function to get the length of a string
 * @str: char * string to get the length of
 * Return: Length of string an int
 */

int _strlen(char *str)
{
	int length = 0, iterator = 0;

	if (str == NULL)
		return (0);
	for (iterator = 0; str[iterator]; iterator++)
		length++;
	return (length);
}
/**
 * _strcpy - copy a string to a new address
 * @src: address of the string to be copied
 * @dest: destination of the new string
 * Return: pointer to the new address
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	if (dest == NULL)
		return (NULL);
	if (src == NULL)
		return (NULL);
	for (i = 0; src[i]; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}
/**
 * _strcat - concantenate 2 strings overwriting the terminating null byte
 * @dest: string to append to
 * @src: string to append
 * Return: the destination address
 */
char *_strcat(char *dest, char *src)
{
	int iter = 0, lendest = _strlen(dest);

	if (src == NULL)
		return (dest);
	if (dest == NULL)
		return (NULL);
	while (src[iter])
	{
		dest[lendest] = src[iter];
		iter++;
		lendest++;
	}
	dest[lendest + 1] = '\0';
	return (dest);
}

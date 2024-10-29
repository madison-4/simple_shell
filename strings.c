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
/**
 * _strcmp - comprae two strings and return the difference
 * It will return 0 if they're equal
 * @s1: string to subtract from
 * @s2: string to sutract
 * Return: difference
 */
int _strcmp(char *s1, char *s2)
{
	int difference = 0, iter = 0;

	while ((*(s1 + iter) == *(s2 + iter)) && s1[iter] && s2[iter])
	{
		iter++;
	}
	difference += (s1[iter] - s2[iter]);
	return (difference);
}

/**
 * _strchr - locate a charactr in a string
 * @s: string to be looked into
 * @c: character to find
 * Return: first occurrence if caracter or NULL if it's not found
 */
char *_strchr(char *s, char c)
{
	int iter;

	for (iter = 0; s[iter]; iter++)
	{
		if (s[iter] == c)
		{
			return (s + iter);
		}
	}
	if (c == '\0')
		return (s + iter);
	return (NULL);
}

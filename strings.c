#include "shell.h"

/**
 * _strlen - a function to get the length of a string
 * @str: char * string to get the length of
 * Return: Length of string an int
 */

int _strlen(char *str)
{
	int length = 0, iterator = 0;

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

	for (i = 0; src[i]; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

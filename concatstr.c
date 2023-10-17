#include "main.h"

/**
 * strCat - a function to concatenate two strings
 * @dest: mew string being created
 * @src: string being copied to dest
 *
 * Return: a new concatenated string
 */

char *strCat(char *dest, char *src)
{
	int i = 0, dest_length = 0;

	while (dest[i++])
	{
		dest_length++;
	}

	for (i = 0; src[i]; i++)
	{
		dest[dest_length++] = src[i];
	}
	dest[dest_length] = '\0';
	return (dest);
}

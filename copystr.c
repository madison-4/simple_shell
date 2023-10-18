#include "main.h"

/**
 * strCopy - copies the content of one string to another
 * @dest: String where it is copying into
 * @src: String being copied
 *
 * Return: New string in dest
 */

char *strCopy(char *dest, char *src)
{
	size_t i = 0;

	if (dest == NULL || src == NULL)
		return (NULL);


	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}

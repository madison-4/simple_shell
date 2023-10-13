#include "main.h"
/**
 * _strpbrk - find a set of bytes in accept that match the first argument
 * @s: string to be scanned
 * @accept: struing with chars to match
 * Return: pointer to first char in s that ciontains accept
 */
char *_strpbrk(char *s, char *accept)
{
	int iter;

	while (*s)
	{
		iter = 0;
		while (accept[iter])
		{
			if (*s == accept[iter])
				return (s);
			iter++;
		}
		s++;
	}
	return (NULL);
}
/**
 * _strtok - split a strin to tokens
 * @str: string to tokenize
 * @delim: specify the delimiter
 * Return: tokens printed
 */
char *_strtok(char *str, const char *delim)
{
	static char *token;
	char *token;

	if (str != NULL)
		token = str;
	else
	{
		if (token == NULL)
			return NULL;
	}

	*start = token;
	token = strpbrk(start, delim);

	if (token != NULL)
	{
		*token = '\0';
		token++;
	}
	return (start);
}

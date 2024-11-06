#include "shell.h"
/**
 * _strtok - a function to clone strtok (man 3 strtok)
 * @s: string to tokenize
 * @del: delimiter string
 * Return: pointer to next token
 */
char *_strtok(char *s, char *del)
{
	static char *olds;
	char *token;

	if (s == NULL)
		s = olds;
	/* Scan leading delimiters and escape them */
	s += _strspn(s, del);
	/* if s is now null the string is only delimiters */
	if (*s == '\0')
	{
		olds = s;
		return (NULL);
	}
	token = s;
	s = _strpbrk(token, del);
	if (s == NULL)
		olds = _strchr(token, '\0');
	else
	{
		*s = '\0';
		olds = s + 1;
	}
	return (token);
}
/**
 * _strspn - find the nunber of matching characters from the beginning
 * @s: stribng to find
 * @accept: from where to find the match
 * Return: number of match
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int len = 0;

	if ((s == NULL) || (accept == NULL))
		return (len);
	while (*s && _strchr(accept, *s++))
		len++;
	return (len);
}
/**
 * _strpbrk - find a set of bytes in accept that match the first argument
 * @s: string to be scanned
 * @accept: string with chars to match
 * Return: pointer to first char in s that contains any byte
 * found in accept
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
 * _strdup - duplicates a string into newly allocated array
 *
 * @str: string to duplicate
 *
 * Return: pointer to new string
 */
char *_strdup(char *str)
{
	int size = 0;
	char *ptr, *ret;

	if (!str)
		return (NULL);

	ptr = str;
	while (*ptr++)
		size++;

	ret = malloc(size + 1);
	if (!ret)
		return (NULL);

	ptr = ret;
	while (*str)
		*ptr++ = *str++;

	*ptr = 0;
	return (ret);
}

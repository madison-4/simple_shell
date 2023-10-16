#include "main.h"
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
 * _strdup - copy a string to a new location in mempory
 * @str: string to be copied
 * Return: pointer to the new string
 */
char *_strdup(char *str)
{
	char *new, *old;
	size_t len = 0;

	if (!(str))
		return (NULL);
	oldstr = new;
	while (

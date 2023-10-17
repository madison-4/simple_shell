#include "main.h"

/**
 * cmpStr - a function to check if two strings are the same
 * @s01: input one
 * @s02: input string two
 *
 * Return: 0 if the strings are the same || 1 if they are not
 */

int cmpStr(char *s01, char *s02)
{
	while (*s01 && (*s01 == *s02))
	{
		s01++;
		s02++;
	}
	if (*s01 == *s02)
		return (0);
	else if (*s01 < *s02)
		return (-1);
	else
		return (1);
}

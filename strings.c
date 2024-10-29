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

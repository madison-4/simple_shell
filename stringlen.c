#include "main.h"

/**
 * strLen - returns the length of a string
 * @input: string input
 *
 * Return: length of the string
 */

size_t strLen(const char *input)
{
	int idx = 0;
	int n = 0;

	for (idx = 0; input[idx] != '\0'; idx++)
		n++;

	return (n);
}

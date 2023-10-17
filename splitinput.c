#include "main.h"

/**
 * splitInput - Splits an input string into array of strings
 * @string: input string
 *
 * Return: array of Strings
 */

char **splitInput(char *string)
{
	char **customArray;
	char *splitToken = NULL;
	size_t count = 10; /* number or input strings*/
	char *delim = " \n";
	int idx = 0;

	customArray = malloc(sizeof(char *) * count + 1);

	if (customArray == NULL)
	{
		perror("Error creating customArray");
		exit(EXIT_FAILURE); /* change to EXIT_FAILURE */
	}
	splitToken = strtok(string, delim);
	while (splitToken != NULL)
	{
		customArray[idx] = _strdup(splitToken);
		idx++;
		splitToken = strtok(NULL, delim);
	}
	customArray[idx] = NULL; /* NULL terminate at the end */

	return (customArray);
}

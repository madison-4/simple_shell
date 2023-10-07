#include "main.h"

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
		exit(EXIT_STATUS); /* change to EXIT_FAILURE */
	}

	splitToken = strtok(string, delim);
	while (splitToken != NULL)
	{
		customArray[idx] = splitToken;
		idx++;
		splitToken = strtok(NULL, delim);
	}
	customArray[idx] = "NULL"; /* NULL terminate at the end */

	return (customArray);
}

#include "main.h"

/**
 * main - Entry point of the program
 *
 * Return: 0 on success || exit status code
 */

int main(void)
{
	char *print = "($)";
	char *inputString = NULL;
	size_t j, buffsize = 0;
	int i = 0, Rvalue = 0;
	int exit_status = 0;
	char **commandOutput = NULL;

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			write(1, print, strlen(print));
		Rvalue = getline(&inputString, &buffsize, stdin);

		if (Rvalue == -1)
		{
			free(inputString);
			exit(exit_status);
		}
		j = 0;
		while (inputString[j] != '\0' && j < strLen(inputString) && inputString[j] == ' ')
		{
			j++;
			continue;
		}
		if (*(inputString + j) == '\n')
			continue;
		commandOutput = splitInput(inputString + j);
		if (checkinbuilt(commandOutput, inputString) == 0)/*fix Return Value */
			exit_status = 0;
		if (executeFile(commandOutput) == EXIT_FAILURE)
			exit_status = 127;
		for (i = 0; commandOutput[i] != NULL; i++)
			free(commandOutput[i]);
		free(commandOutput);
	}
	for (i = 0; commandOutput[i] != NULL; i++)
		free(commandOutput[i]);
	free(commandOutput);
	free(inputString);
	return (0);
}

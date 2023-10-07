#include "main.h"

int main(void)
{
	char *print = "($)";
	char *inputString = NULL;
	size_t buffsize = 0;
	int Rvalue = 0;
	char **commandOutput = NULL;

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			write(1, print, strlen(print));
		Rvalue = _getline(&inputString, &buffsize, stdin);

		if (Rvalue == -1)
		{
			free(inputString);
			exit(EXIT_FAILURE);
		}
		/* tokenize input to create custom Array */
		commandOutput = splitInput(inputString);
		/* check if command is inbuilt command */
		if (checkinbuilt(commandOutput[0]) == 0)/*fix Return Value */
		{
			/* execute inbuilt command and return with status */
		}
		/* else, pass the command to execute function */

	}
	return (EXIT_SUCCESS);
}

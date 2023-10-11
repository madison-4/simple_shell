#include "main.h"

int main(void)
{
	char *print = "($)";
	char *inputString = NULL;
	size_t buffsize = 0;
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
			exit(exit_status);
		}
		/* tokenize input to create custom Array */
		commandOutput = splitInput(inputString);
		/* check if command is inbuilt command */
		printf("Command idx 0:%s\n", commandOutput[0]);
		if (checkinbuilt(commandOutput) == 0)/*fix Return Value */
		{
			/* execute inbuilt command and return with status */
			exit_status = 0;
		}
		if (executeFile(commandOutput) == EXIT_FAILURE)
			exit_status = 127;
		/* else, pass the command to execute function */
		for (i = 0; commandOutput[i] != NULL; i++)
			free(commandOutput[i]);
	}
	free(commandOutput);
	printf("Exit Status is : %d\n", exit_status);
	return (0);
}

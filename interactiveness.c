#include "shell.h"
/**
 * interactive_mode - function to invoke shell commands in interactive mode
 * @argc: argument count
 * @argv: argument vectors passed to main
 * @envp: program environment
 * Return: no return, if it returns it fails
 */
void interactive_mode(int argc, char **argv, char **envp)
{
	char *comm = NULL, *toks[1024];
	size_t commsize, args = 0, commands = 0;
	int status;
	pid_t child;

	(void) argc;
	(void) argv;
	while (1)
	{
		args = 0;
		prompt();
		if (getline(&comm, &commsize, stdin) == -1)
			perror("Could not read line");
		toks[args] = _strtok(comm, " \t\n");
		++args;
		while (toks[args] != NULL)
			toks[args] = _strtok(NULL, " \n\t");
		if ((access(toks[0], F_OK)) == 0)
		{
			child = fork();
			if (child  == 0)
			{
				printf("The next line is execve with the command enetered\n");
				if (execve(toks[0], toks, envp) == -1)
				{
					_fprintf(STDOUT_FILENO, "Could not execute command");
					commands++;
				}
			}
			else
			{
				wait(&status);
				commands++;
			}
		}
		else
		{
			_fprintf(STDERR_FILENO, "The tokenized string is:");
			_fprintf(STDERR_FILENO, toks[0]);
			_fprintf(STDERR_FILENO, ";klsdnvjsnjvk");
		}
	}
}
/**
 * non_interactive - function to call non interactive mode
 * @argc: argument count
 * @argv: arguments passed to main
 * @envp: environ passed to the program
 * Return: no return
 */
void non_interactive(int argc, char **argv, char **envp)
{
	(void) argc;
	(void) argv;
	(void) envp;
}
/**
 * prompt - a function that prints a prompt
 * no argumnts
 * Return: number of characters printed
 */
int prompt(void)
{
	return (write(STDOUT_FILENO, "#Cisfun: ", 9));
}

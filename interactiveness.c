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
	size_t commsize, args = 0;

	while (1)
	{
		args = 0;
		prompt();
		if (getline(&comm, &commsize, stdin) == -1)
			perror("Could not read line");
		toks[args] = _strtok(comm, " \t");
		++args;
		while (toks[args] != NULL)
			toks[args] = _strtok(NULL, " \t");
		if (access(toks[0], F_OK | R_OK | W_OK | X_OK) == 0)
		{
			if (fork() == 0)
			{
				if (execve(toks[0], toks, envp) == -1)
					perror
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

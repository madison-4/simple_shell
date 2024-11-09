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
	char *comm = NULL, **toks;
	size_t commsize, commands = 0;
	int status;
	pid_t child;

	(void) argc;
	while (1)
	{
		prompt();
		if (getline(&comm, &commsize, stdin) == -1)
			perror("Could not read line");
		commands++;
		toks = retcomm(comm);
		if (toks == NULL)
		{
			_fprintf(STDERR_FILENO, argv[0]);
			_fprintf(STDERR_FILENO, ": ");
			_fprintf(STDERR_FILENO, comm);
			_fprintf(STDERR_FILENO, ": ");
			_fprintf(STDERR_FILENO, "not found");
			continue;
		}
		child = fork();
		if (child == 0)
		{
			if ((execve(toks[0], toks, envp)) == -1)
			{
				_fprintf(STDERR_FILENO, toks[0]);
				perror("Could not execute");
			}
			else
			{
				wait(&status);
				free(comm);
			}
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
/**
 * retcomm - function to split a string into arrays
 * The string is the text entered by the user
 * It splits it and returns an arrays of commands and their args
 * @str: string entered by user
 * Return: array of chars to be used or NULL on failure
 */
char **retcomm(char *str)
{
	char **toks, *path, *pat[1024], *newpath;
	size_t args = 0, i = 0;

	toks = malloc(2048 * sizeof(char *));
	if (toks == NULL)
		return (NULL);
	toks[args] = _strtok(str, " \t\n");
	if (toks[args] == NULL)
		return (NULL);
	for (args = 0; toks[args]; args++)
		toks[args] = _strtok(NULL, " \t\n");
	if (access(toks[0], X_OK) == 0)
		return (toks);
	path = _getenv("PATH");
	path = _strdup(path);
	if (path == NULL)
		return (NULL);
	pat[i] = _strtok(path, ":");
	while (pat[i])
	{
		newpath = malloc((_strlen(pat[i]) + _strlen(toks[0]) + 2) * sizeof(char));
		if (newpath == NULL)
			return (NULL);
		newpath = _strcpy(newpath, pat[i]);
		newpath = _strcat(newpath, "/");
		newpath = _strcat(newpath, toks[0]);
		if (access(newpath, X_OK) == 0)
		{
			free(path);
			toks[0] = newpath;
			return (toks);
		}
		i++;
		pat[i] = _strtok(path, ":");
	}
	free(newpath);
	free(path);
	free(toks);
	return (NULL);
}

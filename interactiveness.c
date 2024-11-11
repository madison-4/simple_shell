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

	(void) argc;
	while (1)
	{
		prompt();
		if (getline(&comm, &commsize, stdin) == -1)
			break;
		commands++;
		toks = retcomm(comm);
		if (toks == NULL)
		{
			errprint(commands, argv[0], comm);
			free(comm);
			continue;
		}
		if (fork() == 0)
		{
			if ((execve(toks[0], toks, envp)) == -1)
			{
				perror("Could not execute");
			}
		}
		wait(&status);
		free(toks[0]);
		free(toks);
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
	char *cmd = NULL, **toks;
	size_t n = 0, numcommands = 0;
	int status;

	(void) argc;
	if (getline(&cmd, &n, stdin) == -1)
		exit(EXIT_SUCCESS);
	numcommands++;
	toks = retcomm(cmd);
	if (toks == NULL)
	{
		errprint(numcommands, argv[0], cmd);
		free(cmd);
		exit(EXIT_SUCCESS);
	}
	if (fork() == 0)
	{
		if (execve(toks[0], toks, envp) == -1)
		{
			errprint(numcommands, argv[0], cmd);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
		free(cmd);
	}
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
 * If the command is the full path itself it returns that, else it checks if
 * by appending it to the path it can be execuited then dpoes that and returns
 * the appended string
 * it could append the string the path before executing
 * @str: string entered by user
 * Return: array of chars to be used or NULL on failure
 */
char **retcomm(char *str)
{
	char **toks;
	size_t args = 0;

	toks = malloc(2048 * sizeof(char *));
	if (toks == NULL)
		return (NULL);
	*toks = _strtok(str, " \t\n");
	if (*toks == NULL)
		return (NULL);
	for (args = 1; *(toks + args); args++)
		*(toks + args) = _strtok(NULL, " \t\n");
	if (access(toks[0], X_OK) == 0)
		return (toks);
	return (cmdpatapnd(toks));
}
/**
 * cmdpatapnd - a function that appends the first char p[ointer to the path
 * It then checks if it's an executable and returns it if it is
 * If it isn't it returns NULL
 * @str: pointyer to char
 * Return: appended path or NULL
 */
char **cmdpatapnd(char **str)
{
	char *path, *toks, *newpath;

	path = _getenv("PATH");
	path = _strdup(path);
	if (path == NULL)
		return (NULL);
	toks = _strtok(path, ":");
	while (toks)
	{
		newpath = malloc((_strlen(toks) + _strlen(str[0]) + 2) * sizeof(char));
		newpath = _strcpy(newpath, toks);
		newpath = _strcat(newpath, "/");
		newpath = _strcat(newpath, str[0]);
		if (access(newpath, X_OK) == 0)
		{
			str[0] = newpath;
			free(path);
			return (str);
		}
		toks = _strtok(NULL, ":");
		free(newpath);
	}
	return (NULL);
}

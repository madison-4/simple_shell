#include "main.h"
/**
 * interact - follow interactive mode operations
 * no arguments ( void)
 * Return: nothing, void
 */
void interact(void)
{
	cjar *line, **args;
	int status = -1;

	while (status == -1)
	{
		write(STDOUT_FILENO, "#cisfun$ ", 9);
		line = read_interact();
		args = splitinteractive(line);
		status = execute(args);
		free(line);
		free(args);
		if (status >= 0)
			exit(status);
	}
}
/**
 * read_interact - read input in interactive mode
 * n arguments
 * Return: a chara string o the input
 */
char *read_interact(void)
{
	char *line = NULL;
	size_t bufsize = 0;
	ssize_t charsnum = 0;

	charsnum = getline(&line, &bufsize, stdin);
	if (chars == -1)
	{
		

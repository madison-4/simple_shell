#include "shell.h"
/**
 * main - function to invoke the shell
 * @argc: argument count
 * @argv: arguments passed to main
 * @envp: environment of the program
 * Return: 0 on suiccess, another elsewise
 */
int main(int argc, char **argv, char **envp)
{
	if (isatty(STDIN_FILENO))
		interactive_mode(argc, argv, envp);
	else
		non_interactive(argc, argv, anvp);
	return (0);
}

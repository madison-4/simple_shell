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
	return (write(STDOUT_FILENO,"#Cisfun: ",9));
}

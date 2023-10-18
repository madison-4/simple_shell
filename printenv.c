#include "main.h"
/**
 * _putchar - write a char to stdout
 * @c: char to write
 * Return: 1 on success, non-negative oe on failure
 */
int _putchar(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}
/**
 * _puts - print a string
 * @str: string to print
 * Return: chars printed
 */
int _puts(char *str)
{
	int i = 0;

	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
	_putchar('\n');
	i++;
	return (i);
}
/**
 * printenv - print the environment variables
 * no aruments
 * Return: nothing
 */

void printenv(void)
{
	int i = 0;

	for (i = 0; environ[i] != NULL; i++)
	{
		_puts(environ[i]);
	}
}

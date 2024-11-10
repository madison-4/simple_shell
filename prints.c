#include "shell.h"
/**
 * _fprintf - a function to print a sentence to a file
 * @fd: file descriptor to write to
 * @sent: sentence to write to file
 * Return: number of chars written
 */
int _fprintf(int fd, char *sent)
{
	int sentence = 0, i = 0;

	if (sent == NULL)
		return (sentence);
	while (sent[i])
	{
		sentence += write(fd, &sent[i], 1);
		i++;
	}
	return (sentence);
}
/**
 * numprint - a function that prints a number using recursion
 * @arg: the number to be printed
 * Return: number of digits printed
 */
int numprint(int arg)
{
	unsigned int k = arg;
	int count = 0;

	if (arg < 0)
	{
		_putchar('-');
		count++;
		arg *= -1;
		k = arg;
	}
	k /= 10;
	if (k)
		count += numprint(k);
	count += _putchar(((unsigned int) arg % 10) + 48);
	return (count);
}
/**
 * _putchar - print a char to stdout
 * @c: char to write
 * Return: 1 on success, -1 on error and errno is approproately set
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * errprint - print ungotten command
 * @com: number of command
 * @str: given command
 * Return: number of chars print
 */
int errprint(int com, char *str)
{
	int i = 0;

	i += _fprintf(STDOUT_FILENO, str);
	i += _fprintf(STDOUT_FILENO, ": ");
	i += numprint(com);
	i += _fprintf(STDOUT_FILENO, ": not found");

	return (i);
}

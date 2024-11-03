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

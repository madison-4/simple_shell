#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
/**
 * main - print a prompt and take commands
 * @arc: argument count
 * @arv: argument vector
 * Return: 0 on sucess
 */
int main(void)
{
	char *buffer;
	size_t bufsize = 50, i = 0;
	size_t chars;

	while (1)
	{
		i = 0;
		printf("$ ");
		chars = getline(&buffer, &bufsize, STDIN_FILENO);
	     	while (buffer[i] && (i < chars))
		{
			putchar(buffer[i]);
			i++;
		}
		if (buffer[i] == 0)
			break;
	}
	return (0);
}

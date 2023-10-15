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
	size_t bufsize = 50, i = 0;
	size_t chars;

	chars = (bufsize / i);
	printf("%lu", chars);
	return (0);
}

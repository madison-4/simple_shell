#include "main.h"
/**
 * main - test stat
 * Return: 0
 */
int main(void)
{
	char path[] = "Text.txt";
	int result;
	struct stat filestat;

	result = stat(path, &filestat);

	if (result == 0)
	{
		printf("File size : is equal to %ld bytes\n", filestat.st_size);
	}
	else
	{
		perror("Error");
		return (1);
	}
	return (0);
}

#include "main.h"

/**
 * _getline - reads a line of input from stdin
 * displays line on the stdout
 * @lineptr: a buffer to hold the content read from standard input
 * @n: to calculate the size of the buffer
 * @stream: stream to read from
 *
 * Return: the number of characters read successfully | -1 on failure
 */

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	int idx = 0;
	char buffer[1024];
	ssize_t readBytes = 0;

	for (idx = 0; idx < 1024; idx++)
		buffer[idx] = '\0';

	readBytes = read(0, buffer, sizeof(buffer));
	 /* ssize_t read(int fd, void *buf, size_t count); */

	printf("readBytes is %ld\n", readBytes);
	if (readBytes == -1)
	{
		perror("Error Reading from stream:");
		/*free(buffer);*/
		return (-1);
	}
	buffer[readBytes] = '\0';
	write(STDOUT_FILENO, buffer, readBytes);

	*lineptr = buffer;
	*n = readBytes;

	return (readBytes);
}

/**
int main(void)
{
	size_t n = 0;
	ssize_t RValue = 0;
	char *prompt = NULL, *buffer = NULL;

	prompt = "(&)";
	write(1, prompt, strlen(prompt));
	RValue = _getline(&buffer, &n, stdin);
	printf("Return Value is %lu\n", RValue);

	return (0);
}
*/

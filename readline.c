#include "main.h"

/**
 * _getline - reads input from a stream
 * @lineptr: a buffer array to read input into
 * @n: size of input to read
 * @fd: file descriptor
 *
 * Return: number of bytes Read
 */

ssize_t _getline(char **lineptr, size_t *n, int fd)
{
	/* int idx = 0; */
	/* char buffer[1024]; */
	ssize_t readBytes = 0;

	readBytes = read(fd, (lineptr), sizeof(lineptr));
	 /* ssize_t read(int fd, void *buf, size_t count); */

	printf("readBytes is %ld\n", readBytes);
	if (readBytes == -1)
	{
		perror("Error Reading from stream:");
		/*free(buffer);*/
		return (-1);
	}
	(lineptr)[readBytes] = '\0';
	write(STDOUT_FILENO, (lineptr), readBytes);

	*n = readBytes;

	return (readBytes);
}

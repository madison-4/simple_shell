#include "main.h"
/**
 * _getline - clone getline from Cstdlib
 * @lineptr: line pointer to given buffer
 * @n: size of buffer
 * @fd:  file descriptor of input
 * Return: bytes read on success, -1 on failure
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


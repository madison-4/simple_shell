#include "main.h"

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

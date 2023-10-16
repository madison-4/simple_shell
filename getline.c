#include "main.h"

/**
 * _calloc - allocates memory to an array
 * @nmemb: number of array elements
 * @size: size of bytes to be alloctated to each nmemb elements
 * Return: a pointer to the allocated memory.
*/

void *_calloc(unsigned int nmemb, unsigned int size)
{
	 void *arr_alloc;
	 unsigned int i;

	if (nmemb == 0 || size == 0)
		return (NULL);
	arr_alloc = malloc(nmemb * size);
	if (!arr_alloc)
		return (NULL);
	for (i = 0; i < (nmemb * size); i++)
		((char *) (arr_alloc))[i] = 0;

	return (arr_alloc);
}

/**
 * _getline - gets string from statndard input and stores in a buffer
 * @line: buffer for the string to be stored
 *
 * Return: number of characters read, if errror returns -1;
 */

ssize_t _getline(char **line)
{
	char *buff = _calloc(8096, sizeof(char));
	ssize_t n = 0;

	if (!buff)
		exit(EXIT_FAILURE);
	while ((read(0, &buff[n], 1)) > 0 && (buff[n] != '\n'))
		n++;

	if (buff[n] == '\n')
	{
		*line = malloc(sizeof(char) * (n + 1));
		if (!*line)
			exit(EXIT_FAILURE);
		buff[n] = '\0';
		_strcpy(*line, buff);
		free(buff);
		return (n);
	}
	else if (n != 0)
	{
		buff[n] = '\0';
		*line = malloc(sizeof(char) * (n + 1));
		if (!*line)
			exit(EXIT_FAILURE);
		_strcpy(*line, buff);
		free(buff);
		return (-1);
	}
	else
	{
		if (isatty(0))
			_fprintf(1, "\n", "nill", 0, "nill");
		free(buff);
		exit(status);
	}
}
/**
 * free_array - a function that frees the memmory allocated to an array
 * @arr: the array to be freed
 *
 * Return: void
 */
void free_array(char **arr)
{
	int i;

	if (!arr)
		return;
	for (i = 0; arr[i] != NULL; i++)
		free(arr[i]);
	free(arr);
}

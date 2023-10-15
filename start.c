#include "main.h"
/**
 * main - execute the shell
 * @argc: argument count
 * @argv: vectore array
 * Return: 0 on sucess, non-zero otherwise
 */
int main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
	if (isatty(STDIN_FILENO) == 1)
		interact();
	else if (isatty(STDIN_FILENO) != 1)
		non_interact();
	return (0);
}

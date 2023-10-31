#include "main.h"

/**
 * cp - copies src to desinations
 * @file_to: the destination file
 * @file_from: the source file
 *
 * Return: integer
 */
int cp(char *file_to, char *file_from)
{
	char *buffer[1024];
	int file_to_d, file_from_d, file_from_r, file_to_w;
	int file_from_c, file_to_c;

	file_from_d = open(file_from, O_RDONLY);
	if (file_from_d < 0)
		return (98);

	file_to_d = open(file_to, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (file_to_d < 0)
		return (99);

	file_from_r = read(file_from_d, buffer, 1024);
	if (file_from_r < 0)
		return (98);

	while (file_from_r > 0)
	{
		file_to_w = write(file_to_d, buffer, file_from_r);
		if (file_to_w < 0)
			return (99);
		file_from_r = read(file_from_d, buffer, 1024);
		if (file_from_r < 0)
			return (98);
	}

	file_from_c = close(file_from_d);
	if (file_from_c < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from_c);
		return (100);
	}
	file_to_c = close(file_to_d);
	if (file_to_c < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_to_c);
		return (100);
	}
	return (0);
}

/**
 * main - the main function
 * @ac: the argument count
 * @av: the argument vector
 *
 * Return: always 0
 */
int main(int ac, char **av)
{
	int code;

	if (ac != 3)
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n"), exit(97);

	code = cp(av[2], av[1]);
	switch (code)
	{
		case (98):
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]);
			exit(98);
		case (99):
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]);
			exit(99);
		case (100):
			exit(100);
		default:
			return (0);
	}
}

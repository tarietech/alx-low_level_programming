#include "main.h"

/**
 * read_textfile - reads a text file and prints it to the POSIX output
 * @filename: the given file
 * @letters: is the number of letters should read
 *
 * Return: the actual number of letters to be read
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t r, w;
	char *buf;

	buf = malloc((letters) * sizeof(char));
	if (!buf)
		return (0);
	if (!filename)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	r = read(fd, buf, letters);
	if (r < 0)
		return (0);
	w = write(STDOUT_FILENO, buf, r);
	if (w != r || w < 0)
		return (0);
	close(fd);
	free(buf);
	return (w);
} /* read_textfile */

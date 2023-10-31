#include "main.h"

/**
 * append_text_to_file - appends a text at the end of file
 * @filename: is the given name of the file
 * @text_content: the given content of the file
 *
 * Return: 1 on success, (-1) on fail)
 */
int append_text_to_file(const char *filename, char *text_content)
{
	ssize_t fd, w;
	int len;

	if (!filename)
		return (-1);
	fd = open(filename, O_RDWR | O_APPEND);
	if (fd < 0)
		return (-1);
	if (text_content)
	{
		while (text_content[len])
			len++;
		w = write(fd, text_content, len);
		if (w < 0)
			return (-1);
	}
	return (1);
}

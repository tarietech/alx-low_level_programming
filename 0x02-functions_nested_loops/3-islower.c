#include "main.h"
/**
 * _islower - Shows 1 if the iput is a
 * lowercase character. Another case shows
 * 0
 *
 * @c: The character is in ASCII code
 *
 * Return: 1 for lowercase character. 0 for the rest.
 */
int _islower(int c)
{
	if (c >= 97 && c <= 122)
	{
		return (1);
	}
	else
	{
		return (0);
	}
	_putchar('\n');
}

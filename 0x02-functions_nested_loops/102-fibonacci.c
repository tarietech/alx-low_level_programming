#include <unistd.h>

/**
 * print_alphabet_x10 - Prints the alphabet in lowercase ten times
 */
void print_alphabet_x10(void)
{
	char letter;
	int i;

	for (i = 0; i < 10; i++)
	{
		for (letter = 'a'; letter <= 'z'; letter++)
		{
			write(1, &letter, 1);
		}
	}

	write(1, "\n", 1);
}

/**
 * main - Entry point of the program
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	print_alphabet_x10();

	return (0);
}

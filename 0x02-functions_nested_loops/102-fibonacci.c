#include <unistd.h>

/**
 * print_fibonacci - Prints the first 50 Fibonacci numbers
 */
void print_fibonacci(void)
{
	unsigned long fib[50];  // Use unsigned long to accommodate large Fibonacci numbers
	int i;

	fib[0] = 1;
	fib[1] = 2;

	for (i = 2; i < 50; i++)
	{
		fib[i] = fib[i - 1] + fib[i - 2];
	}

	for (i = 0; i < 49; i++)
	{
		write(1, fib[i] + '0', 1);   // Convert digit to character and write
		write(1, ", ", 2);           // Write comma and space
	}

	write(1, fib[49] + '0', 1);      // Write last number without comma and space
	write(1, "\n", 1);               // Write new line
}

/**
 * main - Entry point of the program
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	print_fibonacci();

	return (0);
}


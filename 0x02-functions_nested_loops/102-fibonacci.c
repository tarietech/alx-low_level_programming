#include <stdio.h>

/**
 * print_fibonacci - Prints the first 50 Fibonacci numbers
 */
void print_fibonacci(void)
{
	int i;
	unsigned long long int fib1 = 1, fib2 = 2, fib_next;

	printf("%llu, %llu", fib1, fib2);

	for (i = 3; i <= 50; i++)
	{
		fib_next = fib1 + fib2;
		printf(", %llu", fib_next);

		fib1 = fib2;
		fib2 = fib_next;
	}

	printf("\n");
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


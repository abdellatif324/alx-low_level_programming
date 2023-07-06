#include "main.h"
/**
 * print_binary - that prints the binary representation of a number.
 * @n:prints its binary representation.
 *
 * Return:  binary representation of a number
 */

void print_binary(unsigned long int n)
{
	unsigned long int b = 1UL << (sizeof(unsigned long int) * 8 - 1);
	int a = 0;

	if (n == 0)
	{
		putchar('0');
		return;
	}

	while (b != 0)
	{
		if (a)
		{
			putchar('0');
		}
		else if ((n & b) != 0)
		{
			putchar('1');
			a = 1;
		}

		b = b >> 1;
	}
}

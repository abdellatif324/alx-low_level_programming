#include "main.h"

/**
 * more_numbers - print more numbers
 */

void more_numbers(void)
{
	int a, k;

	for (a = 1 ; a <= 10 ; a++)
	{
	for (k = 0; k <= 14; k++)
	{
		if (k >= 10)
			_putchar('1');
		_putchar(k % 10 + '0');
	}
		_putchar('\n');

	}
}

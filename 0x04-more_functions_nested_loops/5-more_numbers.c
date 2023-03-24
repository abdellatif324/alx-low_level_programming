#include "main.h"

/*
 * more_numbers - print more numbers
 */

void more_numbers(void)
{
	int c;
	int z;

	for (z = 0 ; z < 10 ; z++)
	{
	for (c = '0'; c <= '9'; c++)
	{
		if(c >= 10)
			_putchar('1');
		_putchar(c % 10 + '0');
	}
		_putchar('\n');

	}
}

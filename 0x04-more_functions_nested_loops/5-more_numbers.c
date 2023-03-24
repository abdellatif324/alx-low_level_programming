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
		_putchar(c);
	}
		_putchar('\n');

	}
}

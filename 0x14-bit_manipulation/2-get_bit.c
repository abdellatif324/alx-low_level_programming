#include "main.h"

/**
 * get_bit -  that returns the value of a bit at a given index.
 * @n: given number
 * @index: Index out of range
 *
 * Return: -1 if error index out of range or return n & mask if not equal 0
 */

int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int a;

	if (index >= sizeof(unsigned long int) * 8)
		return (-1);

	a = 1UL << index;
	return ((n & a) != 0);
}



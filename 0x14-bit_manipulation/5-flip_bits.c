#include "main.h"
/**
 * flip_bits -  that returns the number of bits
 * @n: calculated using the function
 * @m: calculated using the function
 * Return: count
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int xor;
	unsigned int count = 0;

	xor = n ^ m;

	while (xor != 0)
	{
		xor &= (xor - 1);
		count++;
	}

	return (count);
}

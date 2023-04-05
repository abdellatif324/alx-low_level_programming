#include "main.h"
/**
 * factorial - returns the factorial of a number
 * @n: number to return the factorial from
 *
 * Return: factorial of n
 */
int factorial(int n)
{
	if (n >= 0)
	{
		if (n == 0 || n == 1)
			return (1);
		else
			return (n * factorial(n - 1));
	}
	else
	{
		return (-1);
	}
}

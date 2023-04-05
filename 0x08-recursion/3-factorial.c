#include "main.h"
/*
 * _factorial: function that returns the factorial of a given number
 * @n: number given4
 * Return : factorila
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

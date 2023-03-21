#include "main.h"

/**
 * print_alphabet - print alphabet
 *
 * Return: void
 */
int print_alphabet(void)
{
	char lettre = 'a';

	while (lettre <= 'z')
	{	_putchar(lettre);
		lettre++;
	}
	_putchar('\n');
	return (0);
}

#include "main.h"

/**
 * print_alphabet_x10 - print alphabet 10 times
 *
 * Return: void
 */
int print_alphabet_x10(void)

{
	int round = 0;
	 char lettre ;
	while (round < 10)
	{
		lettre = 'a';
	while (lettre <= 'z')
		{
		_putchar(lettre);
		lettre++;
		}
		round++;
		_putchar('\n');
	}
		_putchar('\n');
		return (0);
}

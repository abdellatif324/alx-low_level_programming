#include <stdio.h>
/**
*	main - prints the alphabet
*
*	Return: Always  (Success)
**/
int main(void)
{
	char ch;

	for (ch = 'z'; ch >= 'a' ; ch--)
	{
	putchar(ch);
	}

	putchar('\n');
	return (0);
}

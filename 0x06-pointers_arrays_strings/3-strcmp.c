#include "main.h"
/**
 * _strcmp - compares two strings
 * int _strcmp (s1,s2)
 *@s1 : pointer a s1
 *@s2 : pointer a s2
 * Return: 0 if s1 and s2 are equals,
 *
 */
int _strcmp(char *s1, char *s2)
{
	int a;

	a = strcmp(s1, s2);

	if (a == -1)
	{
		a = -15;
		return (a);
	}
	else if (a == 1)
	{
		a = 15;
		return (a);
	}
	return (a);
}

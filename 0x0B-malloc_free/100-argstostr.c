#include "main.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * argstostr - concatenates all the arguments of your program
 * @ac: argument counter
 * @av: argument vector
 * Return: 0
 */
char *argstostr(int ac, char **av)
{
	char *p;
	int a = 0, b = 0, c = 0, d = 0;

	if (ac == 0 || av == NULL)
		return (NULL);
	while (b < ac)
	{
		c = 0;
		while (av[b][c] != '\0')
		{
			a++;
			c++;
		}
		b++;
	}

	a = a + ac + 1;
	p = malloc(sizeof(char) * a);

	if (p == NULL)
	{
		return (NULL);
	}
	for (b = 0; b < ac; b++)
	{
		for (c = 0; av[b][c] != '\0'; c++)
		{
			p[d] = av[b][c];
			d++;
		}
		p[d] = '\n';
		d++;
	}
	return (p);
}

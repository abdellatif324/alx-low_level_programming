#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * _strdup - pointer to a newly allocated space in memory,
 *
 * @str: Memory for the new string is obtained
 * Return: pointrt toduplicated string it return NULL
 */
char *_strdup(char *str)
{
	char *s;
	unsigned int a, b;

	a = 0;

	if (str == NULL)
		return (NULL);

	while (str[a] != '\0')
		a++;
	s = malloc(sizeof(char) * (a + 1));

	if (s == NULL)
		return (NULL);

	for (b = 0; str[b]; b++)
	{
		s[b] = str[b];
	}
	return (s);
}

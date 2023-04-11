#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * create_array - that creates an array of chars,
 * and intializes it with specific char.
 * description: fuction that creates an array of chars,
 * @size: size of array
 * @c: char of asign
 * Return: pointeur array or NULL
 */
char *create_array(unsigned int size, char c)
{
	char *p;
	unsigned int i;

	p = malloc(sizeof(char) * size);
	if (size == 0 || p == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		p[i] = c;
	return (p);
}

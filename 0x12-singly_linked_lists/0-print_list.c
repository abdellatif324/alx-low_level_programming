#include <stdio.h>
#include "lists.h"
/**
 * print_list - that prints all the elements of a list_t list.
 * @h: pointer to list_t list
 * Return: the number of nodes printed
 */

size_t print_list(const list_t *h)
{
	size_t x = 0;

	while (h)
	{
		if (!h->str)
			printf("[0] (nil)\n");
		else
			printf("[%d] %s\n", h->len, h->str);
		h = h->next;
		x++;
	}
	return (x);
}

#include <stdio.h>
#include "lists.h"
/**
 * print_list - that returns the number of elements in a linked list_t list
 * @h: pointer to list_t list
 * Return: the number of nodes printed
 */

size_t list_len(const list_t *h)
{
	size_t x = 0;

	while (h)
	{
	h = h->next;
		x++;
	}
	return (x);
}

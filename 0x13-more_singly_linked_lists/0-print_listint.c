#include "lists.h"

/**
 * print_listint - prints all the elements of a linked list
 * @h: linked lists
 * Return:  the number of nodes
 */
size_t print_listint(const listint_t *h)
{
	size_t a = 0;

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
		a++;
	}
	return (a);
}


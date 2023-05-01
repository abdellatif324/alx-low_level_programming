#include "lists.h"

/**
 * listint_len - that returns the number of nodes
 * @h: linked lists
 * Return:  the number of nodes
 */
size_t listint_len(const listint_t *h)
{
	size_t a = 0;

	while (h)
	{
		h = h->next;
		a++;
	}
	return (a);
}


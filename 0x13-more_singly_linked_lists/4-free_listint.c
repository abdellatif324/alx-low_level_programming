#include "lists.h"

/**
 * free_listint - that frees a listint_t list.
 * @head: pointer list to be free
 *
 */

void free_listint(listint_t *head)
{
	listint_t *fre;

	while (head)
	{
		fre = head->next;
		free(head);
		head = fre;
	}
}

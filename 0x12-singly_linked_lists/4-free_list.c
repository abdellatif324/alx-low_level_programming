#include <stdlib.h>
#include "lists.h"

/**
 * free_list - that firees a list_t list.
 * @head: list_t list to be freed
 */
void free_list(list_t *head)
{
	list_t *nob;

	while (nob)
	{
		nob = head->next;
		free(head->str);
		free(head);
		head = nob;
	}
}

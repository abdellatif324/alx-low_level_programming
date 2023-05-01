#include "lists.h"

/**
 * add_nodeint_end - that adds a new node at the end
 * @head: pointer list
 * @n: valeur
 *
 * Return: the address of the new element, or NULL if it failed
 */

listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *ptr;
	listint_t *h = *head;

	ptr = malloc(sizeof(int));

	if (!ptr)
	{
		return (NULL);
	}

	ptr->n = n;
	ptr->next = NULL;

	if (*head == NULL)
	{
		*head = ptr;
		return (ptr);
	}

	while (h->next)
		h = h->next;

	h->next = ptr;


	return (ptr);
}

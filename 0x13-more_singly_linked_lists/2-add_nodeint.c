#include "lists.h"

/**
 * add_nodeint - that adds a new node at the beginning
 * @head: pointer list
 * @n: valeur
 *
 * Return: the address of the new element, or NULL if it failed
 */

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *ptr;

	ptr = malloc(sizeof(int));

	if (!ptr)
	{
		return (NULL);
	}

	ptr->n = n;
	ptr->next = *head;
	*head = ptr;

	return (ptr);
}

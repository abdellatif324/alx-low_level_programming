#include "lists.h"

/**
 *  *reverse_listint - that reverses a listint_t
 * @head: pointer to the list
 *
 * Return: pointer
 */

listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = NULL;
	listint_t *suiv = NULL;

	while (*head)
	{
		suiv = (*head)->next;
		(*head)->next = prev;

		prev = *head;
		*head = suiv;
	}
	*head = prev;

	return (*head);
}


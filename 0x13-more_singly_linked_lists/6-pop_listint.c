#include "lists.h"

/**
 * pop_listint - deletes the head node of a linked list
 * @head: pointer list
 * Return: if empty
 */

int pop_listint(listint_t **head)
{
	listint_t *ptr;
	int a;

	if (!head || !*head)
		return (0);

	a = (*head)->n;
	ptr = (*head)->next;

	free(*head);
	*head = ptr;

	return (a);
}


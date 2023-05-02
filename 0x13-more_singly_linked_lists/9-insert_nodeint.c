#include "lists.h"

/**
 * insert_nodeint_at_index - that inserts a new node at a given position.
 * @head: pointer list
 * @idx: index
 * @n: data to insert
 * Return: pointer
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *temp;
	listint_t *point = *head;

	unsigned int a = 0;

	temp = malloc(sizeof(listint_t));

	if (!temp || head)
		return (NULL);

	temp->n = n;
	temp->next = NULL;

	if (idx == 0)
	{
		temp->next = *head;
		*head = temp;
		return (temp);
	}

	for (; point && a < idx; a++)
	{
		if (a == idx - 1)
		{
			temp->next = point->next;
			point->next = temp;

			return (temp);
		}
		else
		{
			point = point->next;
		}
	}
		return (NULL);
}

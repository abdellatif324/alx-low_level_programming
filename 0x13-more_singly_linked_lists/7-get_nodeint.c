#include "lists.h"
/**
 * get_nodeint_at_index -  that returns the nth node of a linked list
 * @head: pointer list
 * @index: index the node,
 * Return: pintr
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *temp = head;
	unsigned int a = 0;

	while (temp && a < index)
	{
		temp = temp->next;
		a++;
	}
	return (temp ? temp : NULL);
}

#include "lists.h"

/**
 * sum_listint - that returns the sum of all the data
 * @head: pointer list
 *
 * Return: sum of all data
 */

int sum_listint(listint_t *head)
{
	int sum_list;
	listint_t *temp = head;

	sum_list = 0;

	while (temp)
	{
		sum_list = sum_list + temp->n;
		temp = temp->next;
	}
	return (sum_list);
}

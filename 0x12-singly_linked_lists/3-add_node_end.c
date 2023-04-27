#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lists.h"
/**
 * add_node_end - that adds a new node at the end of a list_t list.
 * @head: double pointer to list_t
 * @str: new string to add in the node
 * Return: the address of the new elemnt, or NNULL if fails
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *first;
	list_t *temp = *head;
	unsigned int len = 0;

	while (str[len])
		len++;

	first = malloc(sizeof(list_t));
	if (!first)
		return (NULL);

	first->str = strdup(str);
	first->len = len;
	first->next = NULL;

	if (*head == NULL)
	{
		*head = first;
		return (first);
	}

	while (temp->next)
		temp = temp->next;

	temp->next = first;


	return (first);
}

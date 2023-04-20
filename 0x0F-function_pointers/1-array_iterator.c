#include <stddef.h>
#include "function_pointers.h"
#include <stdlib.h>
/**
 * array_iterator - that executes a function given
 * @array: array
 * @size: size the size of the array
 * @action:  is a pointer to the function
 * Return: nothing
 */

void array_iterator(int *array, size_t size, void (*action)(int))
{

	unsigned int i;

	if (!array && !action)
		return;
	for (i = 0; i < size; i++)
	{
		action(array[i]);
	}
}

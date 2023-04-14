#include <stdlib.h>
#include "main.h"
/**
 * *_realloc - reallocates a memory block using malloc and free
 * @ptr: pointer to the memory previsouly allocated by malloc
 * @old_size: size of the allocated memory for ptr
 * @new_size: new size of the new memory block
 * Return: pointer to the newly allocated memory block
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *s;
	char *p;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);

	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}

	if (!ptr)
		return (malloc(new_size));

	s = malloc(new_size);
	if (!s)
		return (NULL);

	p = ptr;

	if (new_size < old_size)
	{
		for (i = 0; i < new_size; i++)
			s[i] = p[i];
	}

	if (new_size > old_size)
	{
		for (i = 0; i < old_size; i++)
			s[i] = p[i];
	}

	free(ptr);

	return (s);
}

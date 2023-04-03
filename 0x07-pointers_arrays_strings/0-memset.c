#include <string.h>
/**
 * _memset - that fills memory with a constant byte
 * @buffer: pointer
 * @b:value
 * @size:size initialiser
 * Return: Nothing.
 */
char *_memset(char *buffer, char b, unsigned int size)
{
		memset(buffer, b, size);
		return (0);
}

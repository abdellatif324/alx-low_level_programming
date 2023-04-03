#include <string.h>
/**
 * _memset - that fills memory with a constant byte
 * @s: pointer
 * @b:value
 * @size:size initialiser
 * Return: s.
 */
char *_memset(char *s, char b, unsigned int size)
{
		memset(s, b, size);
		return (s);
}

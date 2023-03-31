#include "main.h"
/**
 * string_toupper - change all lowercase to uppercase
 * @str: pointer
 *
 * Return: n
 */
char *string_toupper(char *str)
{
	size_t x;

	for (x = 0; x < strlen(str); x++)
	{
	str[x] = toupper(str[x]);
	}
	return (str);
}

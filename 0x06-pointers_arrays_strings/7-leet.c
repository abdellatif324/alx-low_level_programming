#include "main.h"

/**
 * leet - function that encodes a string into 1337
 *
 * Description: function that encodes a string into 1337
 *
 * @str: string input
 *
 * Return: return String in leet
 */

char *leet(char *str)
{
	int index_one, index_two;

	char key[10] = {'a', 'A', 'e', 'E', 'o', 'O', 't', 'T', 'l', 'L'};
	char value[10] = {'4', '4', '3', '3', '0', '0', '7', '7', '1', '1'};

	for (index_one = 0; str[index_one] != '\0'; index_one++)
	{
		for (index_two = 0; index_two < 10; index_two++)
		{
			if (str[index_one] == key[index_two])
			{
				str[index_one] = value[index_two];
			}
		}
	}
	return (str);
}

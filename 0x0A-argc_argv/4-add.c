#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/**
 * main - multiplies two numbers
 * @argc: number of arguments
 * a:convert string a number
 * b:convert string a number
 * @argv: array of arguments
 * Return: 0 (Success), 1 (Error)
 */

int main(int argc, char *argv[])
{
	int a, b;
	int total = 0;

	for (a = 1; a < argc; a++)
	{
		char *arg = argv[a];

		for (b = 0; arg[b] != '\0'; b++)
		{
			if (!isdigit(arg[b]))
			{
				printf("Error\n");
				return (1);
			}
		}

	total += atoi(arg);
	}

	printf("%d\n", total ? total : 0);
	return (0);
}

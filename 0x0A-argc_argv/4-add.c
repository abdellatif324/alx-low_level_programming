#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/**
 * main - that adds positive numbers
 *@argc: argument
 *@argv: argment vector
 *
 *Return: 1 If one of the number contains symbols that are not digits
**/
int main(int argc, char *argv[])
{
	int i, j, num, som;

	for (i = 1; i < argc; i++)
		for (j = 0; argv[i][j] != '\0'; j++)
		{
			if (!isdigit(argv[i][j]))
			{
				printf("Error\n");
				return (1);
			}
			num = atoi(argv[i]);
			som += num;
		}
	printf("%d\n", som);
	return (0);
}

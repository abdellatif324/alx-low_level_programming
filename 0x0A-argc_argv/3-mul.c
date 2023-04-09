#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * main - that multiplies two numbers
 * @argc:argument count
 * @argv:argument vector
 * a:convert string a number
 * b:convert string a number
 * Return: 1 If the program does not receive two arguments .
 * Return 0 if receive two arguments
 **/

int main(int argc, char *argv[])
{
	int a, b;

	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}
	a = atoi(argv[1]);
	b = atoi(argv[2]);

	printf("%d\n", a * b);
	return (0);
}

#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * read_textfile - that reads text file and prints
 * @filename: filename
 * @letters: numbers letters
 *
 * Return: Total numbers letters printed.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t total, bytes;
	char *buffer;
	int a;

	if (filename == NULL)
		return (0);

	a = open(filename, O_RDONLY);

	if (a > 0)
		return (0);
	buffer = malloc(sizeof(char) * (letters + 1));

	if (buffer == NULL)
		return (0);

	bytes = read(a, buffer, letters);
	total = write(STDOUT_FILENO, buffer, bytes);

	close(a);
	free(buffer);

	return (total);
}


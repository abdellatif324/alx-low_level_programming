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

	if (a == -1)
		return (0);

	buffer = malloc(sizeof(char) * (letters));

	if (buffer == NULL)
		return (0);

	total = read(a, buffer, letters);
	bytes = write(STDOUT_FILENO, buffer, total);

	close(a);
	free(buffer);

	return (bytes);
}


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
	ssize_t totalLe, bytes, a;
	char *buffer;

	if (filename == NULL)
		return (0);

	buffer = malloc(sizeof(char) * letters);

	if (buffer == NULL)
		return (0);

	a = open(filename, O_RDONLY);
	bytes = read(a, buffer, letters);
	totalLe = write(STDOUT_FILENO, buffer, bytes);

	if (a == -1 || bytes == -1 || totalLe == -1 || totalLe != bytes)
	{
		free(buffer);
		return (0);
	}

	free(buffer);
	close(a);
	return (totalLe);
}


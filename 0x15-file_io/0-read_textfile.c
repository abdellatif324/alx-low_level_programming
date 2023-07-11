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
	ssize_t a, total, bytes = 0;
	char *buffer;

	if (filename == NULL)
		return (0);

	a = open(filename, O_RDONLY);
	if (a == -1)
		return (0);

	buffer = malloc(sizeof(char) * (letters + 1));
	if (buffer == NULL)
	{
		close(a);
		return (0);
	}
	total = read(a, buffer, letters);
	if (total == -1)
	{
		close(a);
		free(buffer);
		return (0);
	}

	buffer[total] = '\0';
	if (bytes == -1 || bytes != total)
	{
		close(a);
		free(buffer);
		return (0);
	}
	close(a);
	free(buffer);

	return (bytes);
}


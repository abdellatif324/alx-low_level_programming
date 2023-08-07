#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

/**
 * read_textfile - Reads and prints a text file to standard output.
 * @filename: The name of the file to read.
 * @letters: The number of letters to read and print at a time.
 *
 * Return: The actual number of letters read and printed, or 0 on failure.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char buffer[1024];
	ssize_t bytes_read, bytes_written, total_written = 0;
	FILE *file;

	(void)letters;

	if (filename == NULL)
	return (0);

	file = fopen(filename, "r");
	if (file == NULL)
	return (0);

	while ((bytes_read = fread(buffer, sizeof(char), sizeof(buffer), file)) > 0)
	{
	bytes_written = write(STDOUT_FILENO, buffer, bytes_read);
	if (bytes_written < 0)
	{
		fclose(file);
		return (0);
	}

	total_written += bytes_written;

	if ((size_t)bytes_written < (size_t)bytes_read)
		break;
	}

	fclose(file);
	return (total_written);
}

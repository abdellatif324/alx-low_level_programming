#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

/**
 * read_textfile - Reads and prints a text file to standard output.
 * @filename: The name of the file to read.
 * @letters: The number of letters it should read and print.
 *
 * Return: The actual number of letters read and printed, or 0 on failure.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	if (filename == NULL)
		return (0);

	int fd = open(filename, O_RDONLY);
	ssize_t total_read = 0;
	char buffer[1024];
	ssize_t bytes_read;

	if (fd == -1)
		return (0);

	while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0)
	{
		ssize_t bytes_written = write(STDOUT_FILENO, buffer, bytes_read);

		if (bytes_written == -1)
		{
			close(fd);
			return (0);
		}
		total_read += bytes_read;
		if (total_read >= letters)
			break;
	}

	close(fd);
	return (total_read);
}


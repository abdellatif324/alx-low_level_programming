#include <stdio.h>
#include "main.h"
#define BUFFER_SIZE 1024
/**
 * error_exit - check if can be open
 * @code: code from
 * @message: message
 * Return: nothing.
 */
void error_exit(int code, const char *message)
{
	dprintf(STDERR_FILENO, "%s\n", message);
	exit(code);
}

/**
 * main - check the code
 * @argc: number of arguments.
 * @argv: arguments vector
 * Return: always0
 */
int main(int argc, char **argv)
{
	int fd_from, fd_to;
	char buffer[BUFFER_SIZE];
	ssize_t bytes_read, bytes_written;

	if (argc != 3)
		error_exit(97, "Usage: cp file_from file_to");

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		error_exit(98, "Error: Can't read from file");

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_to == -1)
		error_exit(99, "Error: Can't write to file");

	while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written == -1)
			error_exit(99, "Error: Can't write to file");
	}

	if (bytes_read == -1)
		error_exit(98, "Error: Can't read from file");

	if (close(fd_from) == -1 || close(fd_to) == -1)
		error_exit(100, "Error: Can't close fd");

	return (0);
}

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * check_arguments - Checks the number of arguments.
 * @argc: Number of arguments.
 * @argv: Arguments vector.
 *
 * Return: No return value. Exits if the number of arguments is incorrect.
 */
void check_arguments(int argc, char *argv[])
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]);
		exit(97);
	}
}

/**
 * open_file - Opens a file with specified flags and mode.
 * @filename: Name of the file to open.
 * @flags: Flags for opening the file.
 * @mode: Mode for file permissions (only applicable when creating a file).
 *
 * Return: File descriptor of the opened file. Exits on error.
 */
int open_file(const char *filename, int flags, mode_t mode)
{
	int fd = open(filename, flags, mode);

	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
		exit(98);
	}
	return (fd);
}

/**
 * copy_file - Copies content from source file to destination file.
 * @source_fd: File descriptor of the source file.
 * @dest_fd: File descriptor of the destination file.
 *
 * Return: No return value. Exits on read or write errors.
 */
void copy_file(int source_fd, int dest_fd)
{
	ssize_t nchars;
	char buf[1024];

	nchars = 1024;
	while (nchars == 1024)
	{
		nchars = read(source_fd, buf, 1024);
		if (nchars == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file\n");
			exit(98);
		}
		if (write(dest_fd, buf, nchars) == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to file\n");
			exit(99);
		}
	}
}

/**
 * close_file - Closes a file descriptor.
 * @fd: File descriptor to close.
 * @filename: Name of the file associated with the file descriptor.
 *
 * Return: No return value. Exits on error.
 */
void close_file(int fd, const char *filename)
{
	int err_close = close(fd);

	if (err_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd for %s\n", filename);
		exit(100);
	}
}

/**
 * main - Entry point of the program.
 * @argc: Number of arguments.
 * @argv: Arguments vector.
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	int file_from, file_to;

	check_arguments(argc, argv);

	file_from = open_file(argv[1], O_RDONLY, 0);
	file_to = open_file(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);

	copy_file(file_from, file_to);

	close_file(file_from, argv[1]);
	close_file(file_to, argv[2]);

	return (0);
}

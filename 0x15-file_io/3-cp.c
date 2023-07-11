#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

/**
 * error_exit - Prints an error message and exits with a specific code.
 * @code: The exit code.
 * @message: The error message to print.
 */
void error_exit(int code, const char *message)
{
	if (code_from == -1)
	{
		dprintf(STDERR_FILENO, "Error:  %s\n", message);
		exit(98);
	}
	if (file_to == -1)
	{
		dprintf(STDERR_FILENO, "Error : %s\n", message);
		exit(98);
	}
}

/**
 * main - Entry point of the program.
 * @argc: The number of arguments.
 * @argv: The array of arguments.
 *
 * Return: 0 on success, or the appropriate error code on failure.
 */
int main(int argc, char **argv)
{
    int fd_from, fd_to;
    ssize_t bytes_read, bytes_written;
    char buffer[BUFFER_SIZE];
    mode_t permissions = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;

    if (argc != 3)
    {
	    dprintf(STDERR_FILENO, "%s\n", "Usage: cp file_from file_to");
	    exit(97);
    }
    
    fd_from = open(argv[1], O_RDONLY);
    if (fd_from == -1)
        error_exit(98, "Error: Can't read from file");

    fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, permissions);
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

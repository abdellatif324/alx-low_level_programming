#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 64

/**
 * error_exit - Print an error message and exit with the specified code
 * @code: The exit code
 * @message: The error message to be printed
 */
void error_exit(int code, const char *message)
{
	dprintf(STDERR_FILENO, "%s\n", message);
	exit(code);
}

/**
 * print_elf_header - Read and print the information from the ELF header
 * @fd: The file descriptor of the ELF file
 */
void print_elf_header(int fd)
{
	char buffer[BUFFER_SIZE];
	ssize_t bytes_read;
	int i;

	/* Read ELF header */
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read == -1)
		error_exit(98, "Error: Failed to read ELF header");

	/* Print ELF header information */
	printf("ELF Header:\n");
	printf("  Magic:\t");
	for (i = 0; i < 16; i++)
		printf("%02x ", (unsigned char)buffer[i]);
	printf("\n");
	printf("  Class:\tELF%d\n", buffer[4] == 1 ? 32 : 64);
	printf("  Data:\t\t%s\n", buffer[5] == 1 ? "2's complement, little endian" : "2's complement, big endian");
	printf("  Version:\t%d (current)\n", buffer[6]);
	printf("  OS/ABI:\t%s\n", buffer[7] == 0 ? "UNIX - System V" : "UNIX - NetBSD");
	printf("  ABI Version:\t%d\n", buffer[8]);
	printf("  Type:\t\t");
	switch (buffer[16])
	{
		case 1:
			printf("REL (Relocatable file)\n");
			break;
		case 2:
			printf("EXEC (Executable file)\n");
			break;
		case 3:
			printf("DYN (Shared object file)\n");
			break;
		default:
			printf("<unknown>\n");
	}
	printf("  Entry point address:\t0x");
	for (i = 0; i < 8; i++)
		printf("%02x", (unsigned char)buffer[24 + i]);
	printf("\n");
}

/**
 * main - Entry point of the program
 * @argc: The argument count
 * @argv: The argument vector
 *
 * Return: 0 on success, or the corresponding error code
 */
int main(int argc, char **argv)
{
	int fd;

	if (argc != 2)
		error_exit(97, "Usage: elf_header elf_filename");

	/* Open the ELF file */
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_exit(98, "Error: Failed to open ELF file");

	/* Print ELF header */
	print_elf_header(fd);

	/* Close the file */
	if (close(fd) == -1)
		error_exit(100, "Error: Failed to close file");

	return 0;
}


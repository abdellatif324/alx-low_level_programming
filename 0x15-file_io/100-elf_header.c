#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <elf.h>

/**
 * print_error - Prints error message
 * @message: the error message printed
 * Return: nothing
 */
void print_error(const char *message)
{
	printf("Error: %s\n", message);
	exit(98);
}

/**
 * print_elf_header - Prints the information contained in the ELF header.
 * @header: pointer ELF header
 *
 * Return: nothing
 */

void print_elf_header(const Elf64_Ehdr *header)
{
	int i;

	printf("ELF Header:\n");
	printf("  Magic:\t");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x ", header->e_ident[i]);
	printf("\n");

	printf("  Class:\t");
	printf("ELF%d\n", header->e_ident[EI_CLASS] == ELFCLASS64 ? 64 : 32);

	printf("  Data:\t\t");
	printf("%s\n", header->e_ident[EI_DATA] == ELFDATA2LSB ?
	       "2's complement, little endian" :
	       "2's complement, big endian");

	printf("  Version:\t%d (current)\n", header->e_ident[EI_VERSION]);

	printf("  OS/ABI:\t");
	switch (header->e_ident[EI_OSABI])
	{
	case ELFOSABI_NONE:
				printf("UNIX - System V\n");
				break;
	case ELFOSABI_NETBSD:
				printf("UNIX - NetBSD\n");
				break;
	case ELFOSABI_LINUX:
				printf("UNIX - Linux\n");
				break;
	case ELFOSABI_SOLARIS:
				printf("UNIX - Solaris\n");
				break;
	default:
		printf("<unknown: %x>\n", header->e_ident[EI_OSABI]);
		break;
	}
	printf("  ABI Version:\t%d\n", header->e_ident[EI_ABIVERSION]);
	printf("  Type:\t\t0x%x\n", header->e_type);
	printf("  Entry point address:\t0x%lx\n", header->e_entry);
}

/**
 * main - entry point the program
 * @argc: number of commande line arguments
 * @argv: array of string
 * Return: 0 if success or 98 or error
 */
int main(int argc, char *argv[])
{
	int fd;
	Elf64_Ehdr header;
	ssize_t num_read;

	if (argc != 2)
		print_error("Invalid number of arguments");

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		print_error("Failed to open the file");

	num_read = read(fd, &header, sizeof(header));
	if (num_read != sizeof(header))
		print_error("Failed to read the ELF header");

	if (header.e_ident[EI_MAG0] != ELFMAG0 ||
	    header.e_ident[EI_MAG1] != ELFMAG1 ||
	    header.e_ident[EI_MAG2] != ELFMAG2 ||
	    header.e_ident[EI_MAG3] != ELFMAG3)
		print_error("Not an ELF file");

	print_elf_header(&header);

	close(fd);
	return (0);
}


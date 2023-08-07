#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

void display_elf_header(Elf32_Ehdr *header);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char e_ident_class);
void print_data(unsigned char e_ident_data);
void print_version(unsigned char e_ident_version);
void print_osabi(unsigned char e_ident_osabi);
void print_abi_version(unsigned char e_ident_abiversion);
void print_type(Elf32_Half e_type);
void print_entry(Elf32_Addr e_entry);

int main(int argc, char *argv[])
{
	int fd;
	Elf32_Ehdr header;

	/* Check for correct number of arguments */
	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
		exit(98);
	}

	/* Open the ELF file */
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Cannot open file %s\n", argv[1]);
		exit(98);
	}

	/* Read ELF header */
	if (read(fd, &header, sizeof(header)) != sizeof(header))
	{
		dprintf(STDERR_FILENO, "Error: Cannot read ELF header\n");
		close(fd);
		exit(98);
	}

	/* Display ELF header information */
	display_elf_header(&header);
	close(fd);

	return (0);
}

/**
 * display_elf_header - Display information from the ELF header.
 * @header: Pointer to the ELF header structure.
 */
void display_elf_header(Elf32_Ehdr *header)
{
	printf("ELF Header:\n");
	print_magic(header->e_ident);
	print_class(header->e_ident[EI_CLASS]);
	print_data(header->e_ident[EI_DATA]);
	print_version(header->e_ident[EI_VERSION]);
	print_osabi(header->e_ident[EI_OSABI]);
	print_abi_version(header->e_ident[EI_ABIVERSION]);
	print_type(header->e_type);
	print_entry(header->e_entry);
}

/**
 * print_magic - Print the magic numbers from the ELF header.
 * @e_ident: Pointer to the ELF identification bytes.
 */
void print_magic(unsigned char *e_ident)
{
	int i;

	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%2.2x%c", e_ident[i], i == EI_NIDENT - 1 ? '\n' : ' ');
}

/**
 * print_class - Print the ELF class.
 * @e_ident_class: ELF class byte from the identification bytes.
 */
void print_class(unsigned char e_ident_class)
{
	const char *class_str;

	switch (e_ident_class)
	{
		case ELFCLASS32:
			class_str = "ELF32";
			break;
		case ELFCLASS64:
			class_str = "ELF64";
			break;
		default:
			class_str = "<unknown>";
			break;
	}

	printf("  Class:                             %s\n", class_str);
}

/**
 * print_data - Print the ELF data encoding.
 * @e_ident_data: ELF data byte from the identification bytes.
 */
void print_data(unsigned char e_ident_data)
{
	const char *data_str;

	switch (e_ident_data)
	{
		case ELFDATA2LSB:
			data_str = "2's complement, little endian";
			break;
		case ELFDATA2MSB:
			data_str = "2's complement, big endian";
			break;
		default:
			data_str = "<unknown>";
			break;
	}

	printf("  Data:                              %s\n", data_str);
}

/**
 * print_version - Print the ELF version.
 * @e_ident_version: ELF version byte from the identification bytes.
 */
void print_version(unsigned char e_ident_version)
{
	if (e_ident_version == EV_CURRENT)
		printf("  Version:                           1 (current)\n");
	else
		printf("  Version:                           <unknown>\n");
}

/**
 * print_osabi - Print the OS/ABI.
 * @e_ident_osabi: ELF OS/ABI byte from the identification bytes.
 */
void print_osabi(unsigned char e_ident_osabi)
{
	const char *osabi_str;

	switch (e_ident_osabi)
	{
		case ELFOSABI_SYSV:
			osabi_str = "UNIX - System V";
			break;
		case ELFOSABI_NETBSD:
			osabi_str = "UNIX - NetBSD";
			break;
		case ELFOSABI_SOLARIS:
			osabi_str = "UNIX - Solaris";
			break;
		default:
			osabi_str = "<unknown>";
			break;
	}

	printf("  OS/ABI:                            %s\n", osabi_str);
}

/**
 * print_abi_version - Print the ABI version.
 * @e_ident_ab
 * @e_ident_abiversion: ELF ABI version byte from the identification bytes.
 */
void print_abi_version(unsigned char e_ident_abiversion)
{
	printf("  ABI Version:                       %d\n", e_ident_abiversion);
}

/**
 * print_type - Print the ELF type.
 * @e_type: ELF type from the ELF header.
 */
void print_type(Elf32_Half e_type)
{
	const char *type_str;

	switch (e_type)
	{
		case ET_NONE:
			type_str = "NONE (No file type)";
			break;
		case ET_REL:
			type_str = "REL (Relocatable file)";
			break;
		case ET_EXEC:
			type_str = "EXEC (Executable file)";
			break;
		case ET_DYN:
			type_str = "DYN (Shared object file)";
			break;
		case ET_CORE:
			type_str = "CORE (Core file)";
			break;
		default:
			type_str = "<unknown>";
			break;
	}

	printf("  Type:                              %s\n", type_str);
}

/**
 * print_entry - Print the entry point address.
 * @e_entry: Entry point address from the ELF header.
 */
void print_entry(Elf32_Addr e_entry)
{
	printf("  Entry point address:               %#lx\n", (unsigned long)e_entry);
}


#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 64

void error_exit(int code, const char *message)
{
    dprintf(STDERR_FILENO, "%s\n", message);
    exit(code);
}

void print_elf_header(int fd)
{
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;

    // Read ELF header
    bytes_read = read(fd, buffer, BUFFER_SIZE);
    if (bytes_read == -1)
        error_exit(98, "Error: Failed to read ELF header");

    // Print ELF header information
    printf("ELF Header:\n");
    printf("  Magic:   ");
    for (int i = 0; i < 16; i++)
        printf("%02x ", buffer[i]);
    printf("\n");
    printf("  Class:                             ELF%d\n", buffer[4] == 1 ? 32 : 64);
    printf("  Data:                              %s\n", buffer[5] == 1 ? "2's complement, little endian" : "2's complement, big endian");
    printf("  Version:                           %d (current)\n", buffer[6]);
    printf("  OS/ABI:                            %s\n", buffer[7] == 0 ? "UNIX - System V" : "UNIX - NetBSD");
    printf("  ABI Version:                       %d\n", buffer[8]);
    printf("  Type:                              ");
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
    printf("  Entry point address:               0x");
    for (int i = 0; i < 8; i++)
        printf("%02x", buffer[24 + i]);
    printf("\n");
}

int main(int argc, char **argv)
{
    int fd;

    if (argc != 2)
        error_exit(97, "Usage: elf_header elf_filename");

    // Open the ELF file
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        error_exit(98, "Error: Failed to open ELF file");

    // Print ELF header
    print_elf_header(fd);

    // Close the file
    if (close(fd) == -1)
        error_exit(100, "Error: Failed to close file");

    return 0;
}


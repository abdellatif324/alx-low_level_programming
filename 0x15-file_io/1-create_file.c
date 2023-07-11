#include "main.h"

/**
 * create_file - function that creates a file..
 * @filename: filename
 * @text_content: content writed
 *
 * Return: 1 on success, -1 on failure
 */



int create_file(const char *filename, char *text_content)
{
	int file_descriptor;
	ssize_t number, bytes_read;

	if (filename == NULL)
		return (-1);

	file_descriptor = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (file_descriptor == -1)
		return (-1);

	if (!text_content)
		text_content = "";
	for (number = 0; text_content[number]; number++)
		;


	bytes_read = read(file_descriptor, text_content, number);

	if (bytes_read == -1)
		return (-1);

	close(file_descriptor);
	return (1);
}

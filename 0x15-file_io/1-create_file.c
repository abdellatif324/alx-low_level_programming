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
	int file_descriptor, bytes_read;
	int number = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (number = 0; text_content[number];)
			number++;
	}
	file_descriptor = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	bytes_read = write(file_descriptor, text_content, number);


	if (file_descriptor == -1 || bytes_read == -1)
		return (-1);

	close(file_descriptor);
	return (1);
}

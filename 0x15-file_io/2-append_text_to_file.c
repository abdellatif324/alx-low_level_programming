#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: The name of the file.
 * @text_content: The NULL terminated string to add at the end of the file.
 *
 * Return: 1 on success, -1 on failure.
 */

int append_text_to_file(const char *filename, char *text_content)
{
	FILE *file = fopen(filename, "a");
	int success = fprintf(file, "%s", text_content);

	if (filename == NULL)
		return (-1);

	if (text_content == NULL)
		return (1);

	if (file == NULL)
		return (-1);


	fclose(file);

	if (success < 0)
		return (-1);

	return (1);
}


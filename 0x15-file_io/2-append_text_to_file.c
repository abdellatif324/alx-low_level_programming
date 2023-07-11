#include "main.h"

/**
 * append_text_to_file - that appends text at the end of a file
 * @filename: the name of the file.
 * @text_content: add the string
 * Return: 1 uf success or -1 if failure.
 */

int append_text_to_file(const char *filename, char *text_content)
{
	FILE *file;
	size_t count = 0;

	if (filename == NULL)
		return (-1);

	file = fopen(filename, "a");

	if (file == NULL)
		return (-1);

	if (text_content != NULL)
	{
		while (text_content[count])
			count++;
		if (fwrite(text_content, sizeof(char), count, file) != count)
		{
			fclose(file);
			return (-1);
		}
	}
	fclose(file);
	return (1);
}

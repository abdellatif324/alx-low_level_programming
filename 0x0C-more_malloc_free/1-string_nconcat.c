#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * string_nconcat - that concatenates two strings
 * s1:the lengths of s1
 * s2:the lengths of s2
 *
 * Return : concatenated
 **/
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
    	if (s1 == NULL)
	{
		s1 = "";
	}
	if (s2 == NULL)
    	{
		s2 = "";
	}
	size_t s1 = strlen(s1);
	size_t s2 = strlen(s2);
	if (n >= len_s2)
	{
		n = len_s2;
	}
}
	char *concatenated = (char *) malloc((len_s1 + n + 1) * sizeof(char));
		if (concatenated == NULL) 
		{
        		return NULL;
		}
	strcpy(concatenated, s1);
	strncat(concatenated, s2, n);

	concatenated[len_s1 + n] = '\0';

	return concatenated;
}

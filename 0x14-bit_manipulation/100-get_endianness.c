#include "main.h"
/**
 * get_endianness -  that checks the endiannes
 * Return: 0 if big endian, 1 if little endian
 */
int get_endianness(void)
{
	unsigned int a = 1;
	unsigned char *strin = (unsigned char *) &a;

	return ((int)(*strin)i);
}

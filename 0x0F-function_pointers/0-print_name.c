#include "function_pointers.h"
#include <stddef.h>
/**
 * print_name - that prints a name
 * @name: arguments
 * @f:that takes a char*
 * Return : nothing
 */

void print_name(char *name, void (*f)(char *))
{
	if (!name || !f)
		return;
	f(name);
}

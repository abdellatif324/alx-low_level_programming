#include <unistd.h>

/**
 ** _putchar _ writes the character  to stdout
 * @c: the character to print
 *  return 0
 */
int _putchar(char c)
{
	return (write(1 ,&c ,1));
}

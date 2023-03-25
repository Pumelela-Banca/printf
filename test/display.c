#include <unistd.h>

/**
 * _dsplayc - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */


int _displayc(char c)
{
	return (write(1, &c, 1));
}

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
/*
void main(void)
{
	int i;
	char *cals;

	cals = "1234567";
	for (i = 0; cals[i] != '\0'; i++)
	{
		_displayc(cals[i]);
	}
}
*/

#include "main.h"

/**
 * print-string - prints a given string innput
 * 
 * @s: string to be pprinted
 * 
 * Return: void.
*/

void print_string(char *s)
{
    int c;

    c = 0;
    while (s[c] != '\0')
    {
        _displayc(s[c]);
        c++;
    }
}

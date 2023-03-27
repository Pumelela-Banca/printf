#include "main.h"

/**
 * print_num - prints integer number to stdout
 * 
 * @n: number to be printed
 * 
 * Return: number
*/

int print_num(int n)
{
    int i, z;
    if (n < 0)
    {
        _displayc('-');
        n = n * (- 1);
    }

    if (n < 10)
    {
        _displayc('0' + n);
        return (n * 10);
    }
    else
    {
        i = n / 10;
        z = n - print_num(i);
        _displayc('0' + z);
        return(n * 10);
    }
}

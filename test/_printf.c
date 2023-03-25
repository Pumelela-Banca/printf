#include "main.h"

/**
 * _printf - simulate printf from standard library
 * 
 * @format: string to  be passed in
 * 
 * Return: number of characters in format
*/

int _printf(const char *format, ...)
{
    
    return (_countchar(format));
}
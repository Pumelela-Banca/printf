#include "main.h"
#include <stdarg.h>
 

/**
 * _printf - simulate printf from standard library
 * 
 * @format: string to  be passed in
 * 
 * Return: number of characters in format
*/

int _printf(const char *format, ...) {
    int i = 0;
    int printedChar = 0;
    int value;
    va_list args;
    va_start(args, format);

//Print each character
    while (format[i]  != '\0')
    {

        if (format[i] == '\0')
        {
            break;
        }

        //increase character count
        if (format[i]!='%')
        {
            value = write(1, &format[i], 1);
            printedChar = printedChar + value;
            i = i + 1;
            continue;
        }
        if (format[i] =='%')
        {
            //use specific checker function for value type
            switch (format[i + 1])
            {
            case 'c':
                _displayc(va_arg(args, int));
                i++;
                break;
            case 's':
                print_string(va_arg(args, char *));
                i++;
                break;
            case 'i':
                print_num(va_arg(args, int));
                i++;
                break;
            case 'd':
                print_num(va_arg(args, int));
                i++;
                break;
            case '%':
                _displayc('%');
                i++;
                break;
            default:
                i++;
                break;
            }
        }
    }
    //return character count as int
    return (i);
}
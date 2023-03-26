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
    int value, just;
    va_list args;
    va_start(args, format);

    just = 0;
//Print each character
    while (format[i]  != '\0')
    {
        if (just == 1)
        {
            just = 0;
            i++;
            continue;
        }
        if (format[i] == '\0')
        {
            break;
        }
        //increase character count
        if (format[i]!='%')
        {
            value = write(1, &format[i], 1);
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
                just = 1;
                break;
            case 's':
                print_string(va_arg(args, char *));
                i++;
                just = 1;
                break;
            case 'i':
                print_num(va_arg(args, int));
                i++;
                just = 1;
                break;
            case 'd':
                print_num(va_arg(args, int));
                i++;
                just = 1;
                break;
            case '%':
                _displayc('%');
                i++;
                just = 1;
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

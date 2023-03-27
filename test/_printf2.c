#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "display.c"
#include "print_num.c"
#include "print_string.c"
#include "main.h"

int _printf(const char *format, ...) {
    int i = 0;
    int printedChar = 0;
    int value;
    int just;
    va_list args;
    va_start(args, format);

    just = 0;
    if (format == NULL)
    {
        return (-1);
    }
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


void main(void)
{
    int f;
    char *sister;
    
    sister = "betty";

    f = _printf("Hi my nam%c is Tom", 'e');
    _printf("I am %d years old", f);
    _printf("my favorite siter is %s", sister);
    _printf("I love to  cook %% %%");

}
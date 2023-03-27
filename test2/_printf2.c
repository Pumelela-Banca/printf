#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "main.h"

int _printf(const char *format, ...) {
    int i = 0;
    int printedChar = 0;
    int value;
    va_list args;
    va_start(args, format);


    if (format == NULL){
        return (-1);
    }
//Print each character
    while (format[i]) {

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
                dosplayc();
                break;
            
            default:
                i++;
                continue;
            }

    }
    //return character count as int
    return (printedChar);
}

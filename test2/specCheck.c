#include "main.h"


/**
 * specCheck - check that we have a valid specifier
 * Applies relevant function for printing that specific format
 * @format: the specifier (char *)
 *
 * If successful ,Return pointer to function
 * Else Return NULL
 */
int (*specCheck(const char*format))(va_list)
{
    int i;
    func_t myArray[4] = {
            {"c", print_char},
            {"s",print_string},
            {"%",print_pcent},
            {NULL,NULL}};

    for (i = 0; myArray[i].t != NULL; i++){
        if (*(myArray[i].t) == *format){
            return(myArray[i].f);
        }

    }
}

#ifndef _MAIN_H
#define _MAIN_H


#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

//Flags//
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

// SIZES //
#define S_LONG 2
#define S_SHORT 1

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

//Printf//
int _printf(const char *format, ...);

//Specifier Checker Function//
int specCheck(const char *fmt , int *ind, va_list list, char buffer[],
              int flags, int width, int precision, int size);

//Struct for Spec Check//
struct fmt
{
    char fmt;
    int (*fn)(va_list, char[], int, int, int, int);
};

//Definition for fmt type//
typedef struct fmt fmt_t;

///Other Specifier handlers///
int pull_flags(const char *format, int *i);
int pull_width(const char *format, int *i, va_list list);
int pull_precision(const char *format, int *i, va_list list);
int pull_size(const char *format, int *i);

//Character Printer//
int print_char(va_list types, char buffer[],
               int flags, int width, int precision, int size);

//Percent Printer//
int print_percent(va_list types, char buffer[],
                  int flags, int width, int precision, int size);

//String Printer//
int print_string(va_list types, char buffer[],
                 int flags, int width, int precision, int size);

//STRING HANDLER//
int handle_write_char(char c, char buffer[],
                      int flags, int width, int precision, int size);


//INT PRINTER//
int print_int(va_list types, char buffer[],
              int flags, int width, int precision, int size);

//NUMBER HANDLERS//
int write_number(int is_positive, int ind, char buffer[],
                 int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
              int length, char padd, char extra_c);

//POINTER HANDLER//
int write_pointer(char buffer[], int ind, int length,
                  int width, int flags, char padd, char extra_c, int padd_start);

int write_unsgnd(int is_negative, int ind,
                 char buffer[],
                 int flags, int width, int precision, int size);

//Character Checkers//
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);




#endif

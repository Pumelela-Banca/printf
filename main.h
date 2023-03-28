#ifndef _MAIN_H
#define _MAIN_H


#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>


#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16


#define S_LONG 2
#define S_SHORT 1

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024


int _printf(const char *format, ...);


int specCheck(const char *fmt , int *ind, va_list list, char buffer[],
              int flags, int width, int precision, int size);


struct fmt
{
    char fmt;
    int (*fn)(va_list, char[], int, int, int, int);
};


typedef struct fmt fmt_t;


int pull_flags(const char *format, int *i);
int pull_width(const char *format, int *i, va_list list);
int pull_precision(const char *format, int *i, va_list list);
int pull_size(const char *format, int *i);


int print_char(va_list types, char buffer[],
               int flags, int width, int precision, int size);


int print_percent(va_list types, char buffer[],
                  int flags, int width, int precision, int size);


int print_string(va_list types, char buffer[],
                 int flags, int width, int precision, int size);

int handle_write_char(char c, char buffer[],
                      int flags, int width, int precision, int size);


int print_int(va_list types, char buffer[],
              int flags, int width, int precision, int size);

int write_number(int is_positive, int ind, char buffer[],
                 int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
              int length, char padd, char extra_c);

int write_pointer(char buffer[], int ind, int length,
                  int width, int flags, char padd, char extra_c, int padd_start);

int write_unsgnd(int is_negative, int ind,
                 char buffer[],
                 int flags, int width, int precision, int size);

int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);




#endif

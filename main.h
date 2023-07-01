#ifndef _MAIN_H
#define _MAIN_H

#define BUFF_SIZE 1024

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

/**
 * struct Formatmapping - a struct used to map specifiers
 * @specifier: struct member
 * @print_func: struct member
 *
 */
struct Formatmapping
{
	char specifier;
	int (*print_func)(va_list list);
};


int _putchar(char c);

int handle_string(va_list arg);
int handle_char(va_list arg);
int handle_percent(va_list arg);
int handle_decimal(va_list arg);
int handle_integer(va_list arg);
int handle_unsigned_int(va_list arg);
int handle_octal(va_list arg);

int (*get_handle(char specifier))(va_list);

int _printf(const char *format, ...);

#endif /* _MAIN_H */

#ifndef _MAIN_H
#define _MAIN_H

#define BUFF_SIZE 1024

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>


/**
 * struct print_fn -Struct for conversion specifiers and their corresponding
 * functions
 * @specifier: The conversion specifier
 * @fn: The function pointer to the corresponding function.
 */
typedef struct print_fn
{
	char specifier;
	int (*fn)(va_list);
} print_fn_t;


int _printf(const char *format, ...);

int print_char(va_list arg);
int print_string(va_list arg);
int print_integer(va_list arg);
int print_percent(va_list arg);
int print_decimal(va_list arg);
int print_unsigned_int(va_list arg);
int print_binary(va_list arg);
int print_octal(va_list arg);
int print_hexadecimal(va_list arg);
int print_hexadecimal_upper(va_list arg);
int print_pointer(va_list arg);
int print_reverse(va_list arg);
int print_rot13(va_list arg);

int (*get_handle(char specifier))(va_list);

int _putchar(char c);

#endif /* _MAIN_H */

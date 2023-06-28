#ifndef _MAIN_H
#define _MAIN_H

#define BUFF_SIZE 1024

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int handle_string(va_list arg);
int handle_char(va_list arg);
int handle_percent(va_list arg);
int handle_decimal(va_list arg);
int handle_integer(va_list arg);


int _putchar(char c);
int (*get_handle(char specifier))(va_list);
int _printf(const char *format, ...);


#endif /* _MAIN_H */

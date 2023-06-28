#ifndef _HANDLERS_H
#define _HANDLERS_H

#include <stdarg.h>
struct Formatmapping
{
	char specifier;
	int (*print_func)(va_list list);
}; 
int handle_string(va_list arg);
int handle_char(va_list arg);
int handle_percent(va_list arg);
int handle_decimal(va_list arg);
int handle_integer(va_list arg);



#endif /* _HANDLERS_H */


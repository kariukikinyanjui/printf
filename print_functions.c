#include <stdio.h>
#include <limits.h>
#include "main.h"


/**
 * print_char - 
 *
 */
int print_char(va_list arg)
{
	char c;

	c = (char)va_arg(arg, int);
	return (_putchar(c));
}

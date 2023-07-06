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


/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1. 
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

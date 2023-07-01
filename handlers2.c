#include "main.h"



/**
 * handle_unsigned_int - handler for unsigned int
 * @arg: argument to handle
 *
 * Return: number of characters printed
 */
int handle_unsigned_int(va_list arg)
{
	unsigned int num;
	unsigned int count = 0;

	num = va_arg(arg, unsigned int);

	_putchar(num);
	count++;

	return (count);
}

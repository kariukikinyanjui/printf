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
/**
 * handle_binary - a function to handle operations for printing binary
 * @arg: argument to print
 * Return: number of characters printed
 */
int handle_binary(va_list arg)
{
	unsigned int num;
	int count = 0;
	int bits[sizeof(num) * 8];
	int i;

	num = va_arg(arg, unsigned int;

	for (i = sizeof(num) * 8 - 1; i >= 0; i--)
	{
		bits[i] = num & 1;
		num >>= 1;
	}

	for (i = 0 i < sizeof(num) * 8, i++)
	{
		write(1, bits + i, 1);
	}
	return (count);
}

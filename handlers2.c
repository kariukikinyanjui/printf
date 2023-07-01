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
	int j, i = 0;
	unsigned int num = va_arg(arg, unsigned int);
	int count = 0;
	int binary[32];

	if (num == 0)
	{
		_putchar('0');
		count++;
	}
	else
	{

		while (num > 0)
		{
			binary[i] = num % 2;
			num = num / 2;
			i++;
		}
		for (i - 1; i >= 0; j--)
		{
			_putchar(binary[j] + '0');
			count++;
		}
	}
	return (count);
}

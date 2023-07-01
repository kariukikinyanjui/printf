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
 * handle_octal - a function to handle opeation for printing octal
 * @arg: argument to print
 *
 * Return: number of characters printed
 */
int handle_octal(va_list arg)
{
	unsigned int num;
	int j, i, count = 0;
	/* We assume that unsigned in can have at most 21 octal digits */ 	
	char octal[22];

	num = va_arg(arg, unsigned int);

	/* handle case for Zero */
	if (num == 0)
	{
		_putchar('0');
		count++;
	}
	else
	{
		i = 0;

		while (num > 0)
		{
			octal[i] = (num % 8) + '0';
			num = num / 8;
			i++;
		}

		for (j = i - 1; j >= 0; j--)
		{
			_putchar(octal[j]);
			count++;
		}
	}

	return (count);
}

#include "main.h"

/**
 * handle_string - a function to handle operation for 's' specifier
 * @arg: argument to print
 *
 * Return: number of character printed
 */
int handle_string(va_list arg)
{

	char *str = va_arg(arg, char *);
	int count = 0;
	int len = 0;

	while (str[len] != '\0')
	{
		len++;
	}

	write(1, str, len);
	count += len;

	return (count);
}

/**
 * handle_char - a function to handle operation for 'c' specifier
 * @arg: argument to print
 *
 * Return: number of character printed
 */
int handle_char(va_list arg)
{
	char a = va_arg(arg, int);
	int count = 0;

	if (a)
	{
		write(1, &a, 1);
		count++;
	}

	return (count);

}

/**
 * handle_percent - a function to handle operation for printing %
 * @arg: argument to print
 *
 * Return: number of character printed
 */
int handle_percent(va_list arg)
{
	(void)arg;

	_putchar('%');

	return (1);

}

/**
 * handle_decimal - a function to handle operation for printing decimals using
 * '%d' specifier
 * @arg: argument to print
 *
 * Return: number of character printed
 */

int handle_decimal(va_list arg)
{
	int number = va_arg(arg, int);
	int count = 0;

	/* Handle the decimal converstion and print the result */
	char buffer[BUFF_SIZE];
	int len = sprintf(buffer, "%d", number);

	write(1, buffer, len);
	count += len;

	return (count);
}

/**
 * handle_integer - a function to handle operation for printing integer based
 * on '%i' specifier
 * @arg: argument to print
 *
 * Return: number of characters printed
 */
int handle_integer(va_list arg)
{
	int number = va_arg(arg, int);
	int count = 0;

	char buffer[BUFF_SIZE];
	int len = sprintf(buffer, "%i", number);

	write(1, buffer, len);
	count += len;

	return (count);
}



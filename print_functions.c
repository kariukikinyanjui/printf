#include <stdio.h>
#include <limits.h>
#include "main.h"


/**
 * print_char - prints characters
 * @args: function parameter
 * Return: printed character
 */
int print_char(va_list args)
{
	char c;

	c = (char)va_arg(args, int);
	return (_putchar(c));
}
<<<<<<< HEAD
/**
 * print_string - a function that prints a string
 * @args: function parameter
 * Return: number of characters
 */
int print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int char_count = 0;

	while (*str)
	{
		putchar(*str++);
		char_count++;
	}
	return (char_count);
}
/**
 * print_integer - a function that prints an integer
 * @args: function parameter
 * Return: number of characters
 */
int print_integer(va_list args)
{
	int num = va_arg(args, int);
	int char_count = 0;
	int is_negative = 0;

	if (num == 0)
	{
		putchar('0');
		char_count++;
		return (char_count);
	}

	if (num < 0)
	{
		is_negative = 1;
		num = -num;
		putchar('-');
		char_count++;
	}
	int num_digits = 0;
	int temp = num;

	while (temp > 0)
	{
		temp /= 10;
		num_digits++;
	}
	int i, divisor = 1;

	for (i = 1; i < num_digits; i++)
	{
		divisor *= 10;
	}
	while (divisor > 0)
	{
		int digit = num / divisor;
		num %= divisor;
		divisor /= 10;
		putchar(digit + '0');
		char_count++;
	}
	return (char_count);
}
/**
 * print_binary - a function that prints binary
 * @args: function parameter
 * Return: number of characters
 */
int print_binary(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	int char_count = 0, i = 0, j;
	int binary_digits[32];

	if (num == 0);
	{
		putchar('0');
		char_count++;
		return (char_count);
	}

	while (num > 0)
	{
		binary_digits[i] = num % 2;
		num /= 2;
		i++;
	}
	for (j = i - 1; j >= 0; j--)
	{
		putchar(binary_digits[j] + '0');
		char_count++;
	}
	return (char_count);
}
/**
 * print_unsigned_integer - prints unsigned integers
 * @args: function parameter
 * Return: number of characters
 */
int print_unsigned_integer(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	int char_count = 0;

	if (num == 0)
	{
		putchar('0');
		char_count++;
		return (char_count);
	}
	int i, num_digits = 0;
	unsigned int temp = num, divisor = 1;

	while (temp > 0)
	{
		temp /= 10;
		num_digits++;
	}
	for (i = '''c; i = 1; i < num_digits; i++)
	{
		divisor *= 10;
	}
	while (divisor > 0)
	{
		unsigned int digit = num / divisor;
		num %= divisor;
		divisor /= 10;
		putchar(digit + '0');
		char_count++;
	}
	return (char_count);
}
/**
 * print_octal - prints octals
 * @args: function parameter
 * Return: number of characters
 */
int print_octal(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	int char_count = 0;
	int octal_digits[32];
	int i = 0, j;

	if (num == 0)
	{
		putchar('0');
		char_count++;
		return (char_count);
	}
	while (num > 0)
	{
		octal_digits[i] = num % 8;
		num /= 8;
		i++;
	}
	for (j = i - 1; j >= 0; j--)
	{
		putchar(octal_digits[j] + '0');
		char_count++;
	}
	return (char_count);
}
/**
 * print_hexadecimal - prints hexadecimals
 * @args: function parameter
 * Return: number of characters
 */
int print_hexadecimal(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	int char_count = 0;
	int hex_digits[32];
	int j, i = 0;
	int remainder = num % 16;

	if (num == 0)
	{
		putchar('0');
		char_count++;
		return (char_count);
	}
	while (num > 0)
	{

		if (remainder < 10 )
		{
			hex_digits[i] = remainder + '0';
		}
		else
		{
			hex_digits[i] = remainder + 'A' - 10;
		}
		num /= 16;
		i++;
	}
	for (j = i - 1; j >= 0; j--)
	{
		putchar(hex_digits[j]);
		char_count++;
	}
	return (char_count);
}

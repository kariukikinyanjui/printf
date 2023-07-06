#include <stdio.h>
#include <limits.h>
#include <stdint.h>
#include "main.h"


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

/**
 * print_pointer - function that prints pointers based on specifier
 * @args: received specifier
 *
 */
int print_poinnter(va_list arg)
{
	void *ptr;
	uintptr_t ptr_value;
	int index, i,  char_count;
	char hex_digits[16];

	ptr = va_arg(arg, void *);
	ptr_value = (uintptr_t)ptr;
	char_count = 0;

	_putchar('0');
	_putchar('x');
	char_count += 2;

	for (i = (sizeof(uintptr_t) * 2) - 1; i >= 0; i--)
	{
		index = (ptr_value >> (i * 4)) & 0xF;
		_putchar(hex_digits[index]);
		char_count++;
	}
	return (char_count);
}



/**
 * print_reverse - function to print in reverse
 *
 */
int print_reverse(va_list arg)
{
	char *str;
	int i, len, char_count;

	str = va_arg(arg, char *);
	char_count = 0;
	len = 0;

	if (str == NULL)
	{
		char_count += printf("(null)");
		return (char_count);
	}

	while (str[len] != '\0')
	{
		len++;
	}

	for (i = len - 1; i >= 0; i--)
	{
		_putchar(str[i]);
		char_count++;
	}

	return (char_count);
}


/**
 * print_rot13 - function to print 
 *
 */
int print_rot13(va_list arg)
{
	char *str;
	int i, char_count;
	char c;

	for (i = 0; str[i] != '\0'; i++)
	{
		c = str[i];
		if ((c >= 'a' && c <= 'm') || (c >= 'A' && c <= 'M'))
		{
			_putchar(c + 13);
			char_count++;
		}
		else if ((c >= 'n' && c <= 'z') || (c >= 'N' && c <= 'Z'))
		{
			_putchar(c - 13);
			char_count++;
		}
		else
		{
			_putchar(c);
			char_count++;
		}
	}
	return (char_count);
}

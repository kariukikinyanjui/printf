#include "main.h"

int handle_string(va_list arg);
int handle_char(va_list arg);
int handle_percent(va_list arg);
int handle_decimal(va_list arg);
int handle_integer(va_list arg);
int handle_unsigned_int(va_list arg);
int handle_binary(va_list arg);


/**
 * _putchar - writes character to stdout
 * @c: character
 *
 * Return: character to stdout
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * get_handle - a function that selects operation based on specifier
 * @specifier: function parameter
 *
 * Return: matching function pointer or NULL if no match found
 *
 */
int (*get_handle(char specifier))(va_list)
{
	/**
	 *  struct Formatmapping - an array of structures used to map specifier
	 */
	struct Formatmapping format_mappings[] = {
		{'s', handle_string},
		{'c', handle_char},
		{'%', handle_percent},
		{'d', handle_decimal},
		{'i', handle_integer},
		{'u', handle_unsigned_int}
	};
	int i;
	int len = sizeof(format_mappings) / sizeof(format_mappings[0]);

	for (i = 0; i < len; i++)
	{
		if (format_mappings[i].specifier == specifier)
		{
			return (format_mappings[i].print_func);
		}
	}

	/* if no match found */
	return (NULL);
}


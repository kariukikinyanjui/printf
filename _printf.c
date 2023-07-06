#include <stdarg.h>
#include "main.h"



/**
 * _printf - A function that produces output according to a format.
 * @format: format string representing specifiers
 *
 * Returns the number of characters printed(excluding the null byte).
 */
int _printf(const char *format, ...)
{
	int char_count, i, found;
	va_list arg;

	print_fn_t print_fns[] = {
	{'c', print_char},
	{'s', print_string},
	{'i', print_integer},
	{'d', print_integer},
	{'b', print_binary},
	{'u', print_unsigned_int},
	{'o', print_octal},
	{'x', print_hexadecimal},
	{'X', print_hexadecimal_upper},
	{'p', print_pointer},
	{'r', print_reverse},
	{'R', print_rot13},
	{'\0', NULL}
};

	va_start(arg, format);
	char_count = 0;
	found = 0;

	while (*format)
	{
		if (*format != '%')
		{
			_putchar(*format);
			char_count++;
		}
		else
		{
			format++;
			for (i = 0; print_fns[i].specifier != '\0'; i++)
			{
				if (*format == print_fns[i].specifier)
				{
					char_count += print_fns[i].fn(arg);
					found = 1;
					break;
				}
			}
			if (!found)
			{
				_putchar('%');
				_putchar(*format);
				char_count += 2;
			}
		}

		format++;
	}

	va_end(arg);
	return (char_count);
}





#include <stdarg.h>
#include "main.h"

/**
 * _printf -
 *
 */
int _printf(const char *format, ...)
{
	int char_count, i, found;
	va_list arg;
	
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
	return (



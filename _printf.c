#include "main.h"
#include "handlers.h"

/**
 * _printf - a function that writes formated outputs to stdout based on string
 * representing format specifier.
 *
 * Return: on success return count of outputed characters.
 */

int (*get_handle(char specifier))(va_list);
int _putchar(char c);


int _printf(const char *format, ...)
{
	va_list arguments;
	int i = 0, count = 0;
	int (*handle)(va_list);


	va_start(arguments, format);

	while (format != NULL && format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] != '\0')
			{
				handle = get_handle(format[i]);
				if (handle != NULL)
				{
					count += handle(arguments);
				}
				else
				{
					/* Print regular character */
					_putchar(format[i]);
					count++;
				}
				i++;
			}
		}
		else
		{
			/* Print retugla character */
			_putchar(format[i]);
			count++;
			i++;
		}
	}
	va_end(arguments);

	return (count);
}
#include <unistd.h>
#include <stdarg.h>

int (*get_handle(char specifier))(va_list);
int _putchar(char c);

/**
 * _printf - a function that writes formated outputs to stdout based on string
 * representing format specifier.
 * @format: string of format specifiers
 *
 * Return: on success return count of outputed characters.
 */
int _printf(const char *format, ...)
{
	va_list arguments;
	int i = 0, count = 0;
	int (*handle)(va_list);


	va_start(arguments, format);

	while (format != NULL && format[i] != '\0')
	{
		/**
		 * A check for start of format specifier
		 */
		if (format[i] == '%')
		{
			i++;
			/**
			 * Check the next character to use as specifier symbol
			 */
			if (format[i] != '\0')
			{
				/**
				 * pass specifier to handle selector
				 * returns appropraite function to handle
				 * specification
				 */
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

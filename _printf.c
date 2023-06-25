#include "main.h"

/**
 * _printf - function that handles the conversion specifiers c, s and %
 * it prints the output to the standard output stream and returns the
 * numbers printed(exluding the null byte)
 * @format: string that defines the format of the output
 * @...: variable number of arguments which means you can pass
 * any number of arguments of different types after the format parameter
 * Return: total 'num' of characters printed
 */
int _printf(const char *format, ...)
{
	int a, num = 0, len = 0;
	const char *p;
	va_list abs;

	va_start(abs, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == '%')
			{
				write(1, "%", 1);
				num++;
			}
			else if (*format == 'c')
			{
				a = va_arg(abs, int);
				write(1, &a, 1);
				num++;
			}
			else if (*format == 's')
			{
				p = va_arg(abs, const char *);
				while (p[len] != '\0')
					len++;
				write(1, p, len);
				num += len;
			}
			else if (*format == 'r')
			{
				write(1, "Unknown specifier", 17);
				num += 17;
			}
		}
		else
		{
			write(1, format, 1);
			num++;
		}
		format++;
	}
	va_end(abs);
	return (num);
}

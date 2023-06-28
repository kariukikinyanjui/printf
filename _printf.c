#include "main.h"
#include "handlers.h"

int (*get_handle(char specifier))(va_list);
int _putchar(char c);

int _printf(const char *format, ...)
{
	va_list arguments;
	int i = 0, count = 0;
	int (*handle)(va_list);

		
	va_start(arguments, format);
	
	while (format && format[i])
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

	return count;
}		

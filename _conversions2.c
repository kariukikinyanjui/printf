#include "main.h"

/**
 * _printf - function that handles the conversion specifiers d and i
 * @format: string that defines the format of the output
 * @...: variable number of arguments
 * Return: total num of characters printed
 */
int _printf(const char *format, ...)
{
	int digit, len, num = 0;
	char a;
/* variable abs of type va_list is used to hold the variable argument */
	va_list abs;
/*
 * va_start initializes the abs variable to start processing the variable
 * argument based on the format parameter
 */
	va_start(abs, format);
/*
 * code enters a loop that iterates through each character until
 * it reaches '\0'
 */
	while (*format != '\0')
	{
/*
 * if current character is % it means conversion specifier is
 * encountered. Code moves to the next character by incrementing format
 */
		if (*format == '%')
		{
			format++;
/*
 * if next character is d or i it indicates decimal or interger conversion
 * specifier
 */
			if (*format == 'd' || *format == 'i')
			{
/*
 * this argument is extracted from the variable argument
 * using va_arg(abs, int). It assumes the argument is of type int
 */
			digit = va_arg(abs, int);
/* character array buffer is defined to hold the formatted number */
			char buffer[20];
/* snprintf function is used to format the number into the buffer array */
			len = snprintf(buffer, sizeof(buffer), "%d", num);
/*
 * write function is called to write the contents of the buffer array to
 * stdout. the len is passed as the number of bytes to write. The num of
 * charactes is incremented by the return value of write
 */
			num += write(1, buffer, len);
			}
		}
		else
		{
/* if % is not found, it means a regular character to be printed stored in a */
			a = *format;
/* write is called to write char a to stdout. the num is incremented */
			num += write(1, &a, 1);
		}
		format++;/* incremented to move the the next character */
	}
/* va_end(abs) macro is called to clean up the abs variable */
	va_end(abs);
/* num holds the total number of characters printed */
	return (num);
}

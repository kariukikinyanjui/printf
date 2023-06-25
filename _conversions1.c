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
	/* abs is declared to hold variable arguments */
	va_list abs;
	/*
	 * va_start macro initializes abs to point to the1st variable
	 * 1st variableargument based on the provided format string
	 */
	va_start(abs, format);
	/*
	 * we use variable num that we initialized. It will keep track
	 * of the number of characters printed
	 */
	/*
	 * we enter a while loop that iterates over each character in the
	 * format string pointed to by the format parameter
	 */
	while (*format != '\0')
	/*
	 * the code checks if it is a % indicating the start
	 * of a conversion specifier
	 */
	{
		if (*format == '%')
		/*
		 * if % is found, the code increments the format pointer
		 * to examine the next character
		 */
		{
			format++;
			if (*format == '\0')
			/* if next character is '\0' the loop is broken */
				break;
			if (*format == '%')
			/*
			 * if next character is  %, it means a
			 * literal % should be printed
			 */
			{
				write(1, "%", 1);
				/*
				 * write is used to print % and num variable
				 * is incremented by 1
				 */
				num++;
			}
			else if (*format == 'c')
			/*
			 * c is a character argument. It is extracted using
			 * va_arg macro passing the abs variable and type
			 * of the argument(int)
			 */
			{
				a = va_arg(abs, int);
				write(1, &a, 1);
				/*
				 * use write to print the character and
				 * num is incremented by 1
				 */
				num++;
			}
			else if (*format == 's')
			/*
			 * s is string argument. It is extracted using macro
			 * va_arg as a pointer to const char *.The code
			 * iterates over the string to determine its length
			 * and stores it in the len variable
			 */
			{
				p = va_arg(abs, const char *);
				while (p[len] != '\0')
					len++;
				write(1, p, len);
				/*
				 * write prints the string and the num variable
				 * is incremented by the length of the string
				 */
				num += len;
			}
		}
		else
		/*
		 * if none of the cases are met, it means a regular character
		 * should be printed
		 */
		{
			write(1, format, 1);
			/*
			 * write prints the character and num is incremented
			 * by 1
			 */
			num++;
		}
		format++;
		/*
		 * after each character is processed the format pointer is
		 * incremented to move to the next character
		 */
	}
	va_end(abs);
	/* va_end macro is used to clean up the variable argument list */
	return (num);
	/* num represents the total number of characters printed */
}

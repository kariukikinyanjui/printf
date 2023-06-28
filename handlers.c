#include "main.h"
#include "handlers.h"


int _putchar(char c)
{
	return (write(1, &c, 1));
}

int handle_string(va_list arg)
{
	
	char *str = va_arg(arg, char *);
	int count = 0;
	int len = 0;
	while (str[len] != '\0')
	{
	
		len++;
		write (1, str, len);

		count += len;
	}
	return (count);
}
	

int handle_char(va_list arg)
{
	char a = va_arg(arg, int);
	int count = 0;
	if (a)
	{
		write(1, &a, 1);
	}	
	
	return (count);

}

int handle_percent(va_list arg)
{
	int count = 0;

	write(1, "%", 1);
	count++;

	return (count);

}

int handle_decimal(va_list arg)
{
	int number = va_arg(arg, int);
	int count = 0;

	/* Handle the decimal converstion and print the result */
	char buffer[BUFF_SIZE];
	int len = sprintf(buffer, "%d", number);
	write(1, buffer, len);
	count += len;

	return (count);
}

int handle_integer(va_list arg)
{
	int number = va_arg(arg, int);
	int count = 0;

	char buffer[BUFF_SIZE];
	int len = sprintf(buffer, "%i", number);
	write(1, buffer, len);
	count += len;

	return (count);
}

#include "main.h"

/**
 * _printf - function to print strings
 * @format: pointer to constant char
 * Return: returns count of chars printed except null byte
 */

int _printf(const char *format, ...)
{
	int counter;
	const char *ptr;
	va_list ap;
	va_start(ap, format);
	
	for (ptr = format; *ptr; ptr++)
	{
		if (*ptr != '%')
		{
			putchar(*ptr);
			counter++;
		}
		else
		{
			counter++;
			if (*ptr == 'd')
			{
				int d = va_arg(ap, int);
				putchar(d + '0');
				counter++;
			}
			else if(*ptr == 'i')
			{
				int i = va_arg(ap, int);
				putchar(i + '0');
				counter++;
			}
			else
			{
				putchar(*ptr);
				counter++;
			}
		}
	}
	return (counter);
}

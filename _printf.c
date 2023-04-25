#include <stdio.h>
#include <stdarg.h>
#include "main.h"
#include <stdarg.h>

/**
 * _printf - function to print strings
 * @format: pointer to constant char
 * Return: returns count of chars printed except null byte
 */

int _printf(const char *format, ...)
{
	int counter;
	const char *ptr;
	int i;
	va_list ap;

	va_start(ap, format);

	for (ptr = format; *ptr; ptr++)
	{
		if (*ptr == '%')
		{
			ptr++;
			 if (*ptr == 'c')
			 {
				 char c = va_arg(ap, int);
				 putchar(c);
				 counter++;
			 }
			 if (*ptr == '%')
			 {
				 putchar(37);
				 counter++;
			 }
			 if (*ptr == 's')
			 {
				 char *str = va_arg(ap, char *);
				 for (i = 0; str[i] != '\0'; i++)
				 {
					 putchar(str[i]);
					 counter++;
				 }
			 }
			else
			{
				return (-1);
			}
		}
		else
		{
			putchar(*ptr);
			ptr++;
			counter++;
		}
	}
		va_end(ap);
		return (counter);
}

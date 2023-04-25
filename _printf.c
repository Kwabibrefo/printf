#include <stdio.h>
#include <stdarg.h>
#include "main.h"
#include <stdarg.h>

/**
 * _printf - function to print strings
 * @format: pointer to constant char
 * Return: returns count of chars printed except null byte
 */

int _printf(const char *format, ...);
{
	va_list ap;
	int counter;

	va_start(ap, counter);
	for (format; *format; format++)
	{
		if (*format == %)
		{
			format++;
			 if (*format == 'c')
			 {
				 char c = va_arg(ap, int);
				 putchar('c')
				 count++;
			 }
			 if (*format == %)
			 {
				 putchar(37);
				 count++;
			 }
			 if (*format == s)
			 {
				 char *str = va_arg(args, char *);
				 for (i = 0; str[i] != '\0'; i++)
				 {
					 putchar('str[i]');
					 count++;
				 }
			 }
			else
			{
				return (-1);
			}
		}
		else
		{
			write(STDOUT_FILENO, format, 1);
			count++;
		}
		va_end (ap);
		return (count);
	}
}

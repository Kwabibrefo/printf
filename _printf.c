#include "main.h"

/**
 * _printf - function to print strings
 * @format: pointer to constant char
 * Return: returns count of chars printed except null byte
 */

int _printf(const char *format, ...)
{
	int counter, i;
	const char *ptr;
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
			else if (*ptr == '%')
			{
				putchar('%');
				counter++;
			}
			else if (*ptr == 's')
			{
				char *str = va_arg(ap, char *);

				for (i = 0; str[i] != '\0'; i++)
				{
					putchar(str[i]);
					counter++;
				}
			}
			else
				return (-1);
		}
		else
		{
			putchar(ptr);
			ptr++;
			counter++;
		}
	}
		va_end(ap);
		return (counter);
}

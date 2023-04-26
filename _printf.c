#include "main.h"

/**
 * _printf - function to print strings
 * @format: pointer to constant char
 * Return: returns count of chars printed except null byte
 */

int _printf(const char *format, ...)
{
	int counter, o;
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

				for (o = 0; str[o] != '\0'; o++)
				{
					putchar(str[o]);
					counter++;
				}
			}
			else if (*ptr == 'd')
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
		va_end(ap);
		return (counter);
}

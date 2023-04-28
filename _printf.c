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
	char *start;
	va_list ap;
	params_t params = PARAMS_INIT;
	
	va_start(ap, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	
	for (ptr = format; *ptr; ptr++)
	{
		init_params(&params, ap);
		if (*ptr != '%')
		{
			counter += _putchar(*ptr);
			continue;
		}
		start = ptr;
		ptr++;
		while (get_flag(ptr, &params))
		{
			ptr++;
		}
		ptr = get_width(ptr, &params, ap);
		ptr = get_precision(ptr, &params, ap);
		if (get_modifier(p, &params))
			ptr++;
		if (!get_specifier(ptr))
			counter += print_from_to(start, ptr,
						 params.l_modifier || params.h_modifier ? p - 1 : 0);
		else
			counter += get_print_func(p, ap, &params);
	}
	_putchar(BUF_FLUSH);
	va_end(ap);
	return (counter);
}

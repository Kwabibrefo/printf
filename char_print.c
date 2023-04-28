#include "main.h"
/**
 * char_print - print character
 * @param: prameters struct
 * @ap: argument pointer
 * Return: char
*/
int char_print(va_list ap, params_t *params)
{
char pad_char = ' ';
unsigned int pad = 1, sum = 0, ch = va_arg(ap, int);

if (params->minus_flag)
sum += _putchar(ch);
while (pad++ < params->width)
sum += _putchar(pad_char);
if (!params->minus_flag)
sum += _putchar(ch);
return (sum);
}
/**
 * int_print - print integer
 * @param: prameters struct
 * @ap: argument pointer
 * Return: char
*/
int int_print(va_list ap, params_t *params)
{
long l;
if (params->l_modifier)
l = va_arg(ap, long);
else if (params->h_modifier)
l = (short int)va_arg(ap, int);
else
l = (int)va_arg(ap, int);
return (number_print(convert(l, 10, 0 params), params));
}

/**
 * string_print - print string
 * @param: prameters struct
 * @ap: argument pointer
 * Return: char
*/
int string_print(va_list ap, params_t *params)
{
char *str = va_arg(ap, char *), pad_char = ' ';
unsigned int pad = 0, sum = 0, i = 0, j;
(void)params;
switch ((int)(!str))
case 1:
str = NULL_STRING;
j = pad = _strlen(str);
if (params->percision < pad)
j = pad = params->percision;
if (params->minus_flag)
{
if (params->percision != UINT_MAX)
for (i = 0; i < pad; i++)
sum += _putchar(*str++);
else
sum += _puts(str);
}
while (j++ < params->width)
sum += _putchar(pad_char);
if (!params->minus_flag)
{
if (params->percision != UINT_MAX)
for (i = 0; i < pad; i++)
sum += _putchar(*str++);
else
sum += _puts(str);
}
return (sum);
}

/**
 * percent_print - print percent
 * @param: prameters struct
 * @ap: argument pointer
 * Return: char
*/
int percent_print(va_list ap, params_t *params)
{
(void)ap;
(void)params;
return (_putchar('%'));
}

/**
 * S_print - print specifier
 * @param: prameters struct
 * @ap: argument pointer
 * Return: char
*/
int S_print(va_list ap, params_t *params)
{
char *str = va_arg(ap, char *);
char *hex;
int sum = 0;

if ((int)(!str))
return (_puts(NULL_STRING));
for (; *str; str++)
{
if ((*str > 0 && *str < 32) || *str >= 127)
{
sum += _putchar('\\');
sum += _putchar('x');
hex = convert(*str, 16, 0, params);
if (!hex[1])
sum += _putchar('0');
sum += _puts(hex);
}
else
{
sum += _putchar(*str);
}
}
return (sum);
}

#include "main.h"
/**
 * _isdigit - check if c is dighit
 * @c: the character to check
 * Return: 1 success
*/
int _isdigit(int c)
{
return (c >= '0' && c <= '9');
}

/**
 * _strlen - check if c is dighit
 * @s: the character to check
 * Return: 1 success
*/
int _strlen(char *s)
{
int i = 0;
while (*s++)
i++;
return (i);
}

/**
 * number_print - print number
 * @str: string
 * @params: parameter struct
 * Return: char
*/
int number_print(char *str, params_t *params)
{
unsigned int i = _strlen(str);
int neg = (!params->unsign && *str == '-');
if (!params->percision && *str == '0' && !str[1])
str = "";
if (neg)
{
str++;
i--;
}
if (params->percision != UINT_MAX)
while (i++ < params->percision)
*--str = '0';
if (neg)
*--str = '-';
if (!params->minus_flag)
return (print_number_right_shift(str, params));
else
return (print_number_left_shift(str, params));
}

/**
 * print_number_right_shift - print number
 * @str: string
 * @params: parameter struct
 * Return: char
*/
int print_number_right_shift(char *str, params_t *params)
{
unsigned int n = 0, neg, neg1, i = _strlen(str);
char pad = ' ';

if (params->zero_flag && !params->minus_flag)
pad = '0';
neg = neg1 = (!params->unsign && *str == '-');
if (neg && i < params->width && pad == '0' && !params->minus_flag)
str++;
else
neg = 0;
if ((params->plus_flag && !neg1) ||
(!params->plus_flag && params->space_flag && !neg1))
i++;
if (neg && pad == '0')
n += _putchar('-');
if (params->plus_flag && !neg1 && pad == '0' && !params->unsign)
n += _putchar(+);
else if (!params->plus_flag && params->space_flag && !neg1 &&
!params->unsign && params->zero_flag)
n += _putchar(' ');
while (i++ < params->width)
n += _putchar(pad);
if (neg && pad == ' ')
n += _putchar('-');
if (params->plus_flag && !neg1 && pad == ' ' && !params->unsign)
n += _putchar('+');
else if (!params->plus_flag && params->space_flag && !neg1 &&
!params->unsign && !params->zero_flag)
n += _putchar(' ');
n += _puts(str);
return (n);
}
/**
 * print_number_left_shift - print number
 * @str: string
 * @params: parameter struct
 * Return: char
*/
int print_number_left_shift(char *str, params_t *params)
{
unsigned int n = 0, neg, neg1, i = _strlen(str);
char pad = ' ';

if (params->zero_flag && !params->minus_flag)
pad = '0';
neg = neg1 = (!params->unsign && *str == '-');
if (neg && i < params->width && pad == '0' && !params->minus_flag)
str++;
else
neg = 0;

if (params->plus_flag && !neg1 && !params->unsign)
n += _putchar('+'), i++;
else if (params->space_flag && !neg1 && !params->unsign)
n += _putchar(' '), i++;
n += _puts(str);
while (i++ < params->width)
n += _putchar(pad);
return (n);
}

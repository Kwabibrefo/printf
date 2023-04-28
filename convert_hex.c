#include "main.h"
/**
 * hex_print - print hex lowercase
 * @param: prameters struct
 * @ap: argument pointer
 * Return: void
*/
int hex_print(va_list ap, params_t *params)
{
unsigned long l;
int c = 0;
char *str;

if (params->l_modifier)
l = (unsigned long)va_arg(ap, unsigned long);
else if (params->h_modifier)
l = (unsigned short int)va_arg(ap, unsigned int);
else
l = (unsigned int)va_arg(ap, unsigned int);
str = convert(l, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
if (params->hashtag_flag && l)
{
*--str = 'x';
*--str = '0';
}
params->unsign = 1;
return (c += number_print(str, params));
}
/**
 * HEX_print - print hex uppercase
 * @param: prameters struct
 * @ap: argument pointer
 * Return: void
*/
int HEX_print(va_list ap, params_t *params)
{
unsigned long l;
int c = 0;
char *str;

if (params->l_modifier)
l = (unsigned long)va_arg(ap, unsigned long);
else if (params->h_modifier)
l = (unsigned short int)va_arg(ap, unsigned int);
else
l = (unsigned int)va_arg(ap, unsigned int);
str = convert(l, 16, CONVERT_UNSIGNED, params);
if (params->hashtag_flag && l)
{
*--str = 'X';
*--str = '0';
}
params->unsign = 1;
return (c += number_print(str, params));
}

/**
 * binary_print - print binary number
 * @param: prameters struct
 * @ap: argument pointer
 * Return: void
*/
int binary_print(va_list ap, params_t *params)
{
unsigned int n = va_arg(ap, unsigned int);
char *str = convert(n, 2, CONVERT_UNSIGNED, params);
int c = 0;
if (params->hashtag_flag && n)
*--str = '0';
params->unsign = 1;
return (c += number_print(str, params));
}
/**
 * octal_print - print binary number
 * @param: prameters struct
 * @ap: argument pointer
 * Return: void
*/
int octal_print(va_list ap, params_t *params)
{
unsigned long l;
int c = 0;
char *str;

if (params->l_modifier)
l = (unsigned long)va_arg(ap, unsigned long);
else if (params->h_modifier)
l = (unsigned short int)va_arg(ap, unsigned int);
else
l = (unsigned int)va_arg(ap, unsigned int);
str = convert(l, 8, CONVERT_UNSIGNED, params);
if (params->hashtag_flag && l)
*--str = '0';
params->unsign = 1;
return (c += number_print(str, params));
}

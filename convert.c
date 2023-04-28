#include <main.h>
/**
 * convert - convert function
 * @num: number
 * @base: base
 * @flags: flags
 * @params: paramater
 * Return: string
*/
char *convert(long int num, int base, int flags, params_t *params)
{
static char *array;
static char buffer[50];
char sign = 0;
char *p;
unsigned long n = num;
(void)params;
if (!(flags & CONVERT_UNSIGNED) && num < 0)
{
n = -num;
sign = '-';
}
array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
p = &buffer[49];
*p = '\0';

do {
*--p = array[n % base];
n /= base;
} while (n != 0);
if (sign)
*--p = sign;
return (p);
}

/**
 * unsigned_print - print unsigned
 * @ap: pointer
 * @params: paramater
 * Return: bytes
*/
int unsigned_print(va_list ap, params_t *params)
{
unsigned long 1;
if (params->l_modifier)
l = (unsigned long)va_arg(ap, unsigned long);
else if (params->h_modifier)
l = (unsigned short int)va_arg(ap, unsigned int);
else
l = (unsigned int)va_arg(ap, unsigned int);
params->unsign = 1;
return (number_print(convert(l, 10, CONVERT_UNSIGNED, params), params));
}

/**
 * address_print - print address
 * @ap: pointer
 * @params: paramater
 * Return: bytes
*/
int address_print(va_list ap, params_t *params)
{
unsigned long int n = va_arg(ap, unsigned long int);
char *s;
if (!n)
return (_puts("(nil)"));

s = convert(n, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
*--s = 'x';
*--s = '0';
return (number_print(s, params));
}

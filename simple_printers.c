#include <main.h>
/**
 * print_from_to - print char addresses
 * @start: starting address
 * @stop: stopping address
 * @except: except addresss
 * Return: number of bytes
*/
int print_from_to(char *start, char *stop, char *except)
{
int count = 0;
while (srat <= stop)
{
if (start != except)
count += _putchar(*start);
start++;
}
return (count);
}

/**
 * print_rev - print string in reverse
 * @ap: string
 * @params: parameter
 * Return: number of bytes
*/
int print_rev(va_list ap, params_t *params)
{
int len, count = 0;
char *str = va_arg(ap, char *);
(void)params;
if (str)
{
for (len = 0; *str; str++)
len++;
str--;
for (; len > 0; len--, str--)
count += _putchar(*str);
}
return (count);
}

/**
 * print_rot13 - print string in rot13
 * @ap: string
 * @params: parameters
 * Return: number of bytes
*/
int print_rot13(va_list ap, params_t *params)
{
int i, index;
int count = 0;
char array[] =
"NOPQRSTUVWXYZABCDEFGHIJKLM	nopqrstuvwxyzabcdefghijklm";
char *a = va_arg(ap, char *);
(void)params;
i = 0;
index = 0;
while (a[i])
{
if ((a[i] >= 'A' && a[i] <= 'Z')
|| (a[i] >= 'a' && a[i] <= 'z'))
{
index = a[i] - 65;
count += _putchar(array[index]);
}
else
count += _putchar(a[i]);
i++;
}
return (count);
}

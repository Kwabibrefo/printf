#include <main.h>
/**
 * _puts - print string
 * @str: string
 * Return: void
*/
int _puts(char *str)
{
char *a = str;

while (*str)
_putchar(*str++);
return (str - a);
}
/**
 * _putchar - print string
 * @c: string
 * Return: on success 1
*/
int _putchar(int c)
{
static int j;
static char buf[OUTPUT_BUF_SIZE];
if (c == BUF_FLUSH || j >= OUTPUT_BUF_SIZE)
{
write(1, buf, j);
i = 0;
}
if (c != BUF_FLUSH)
buf[j++] = c;

return (1);
}

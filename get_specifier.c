#include <main.h>
/**
 * get_specifier - format function
 * @s: format string
 * Return: number of bytes
*/
int (*get_specifier(char *s))(va_list ap, params_t *params)
{
specifier_t specifier[] = {
{"c", char_print},
{"d", int_print},
{"i", int_print},
{"s", string_print},
{"%", percent_print},
{"b", binary_print},
{"o", octal_print},
{"u", unsigned_print},
{"x", hex_print},
{"X", HEX_print},
{"p", address_print},
{"S", S_print},
{"r", print_rev},
{"R", print_rot13},
{NULL, NULL}
};
int i = 0;
while (specifier[i].specifier)
{
if (*s == specifier[i].specifier[0])
{
return (specifier[i].f);
}
i++;
}
return (NULL);
}

/**
 * get_print_func - format function
 * @s: format string
 * @ap: pointer
 * @params: parameters struct
 * Return: number of bytes
*/
int get_print_func(char *s, va_list ap, params_t *params)
{
int (*f)(va_list, params_t *) = get_specifier(s);
if (f)
return (f(ap, params));

return (0);
}

/**
 * get_flag - finds the flag func
 * @s: format string
 * @params: parameters struct
 * Return: number of bytes
*/
int get_flag(char *s, params_t *params)
{
int i = 0;
switch (*s)
{
case '+':
i = params->plus_flag = 1;
break;
case ' ':
i = params->space_flag = 1;
break;
case '#':
i = params->hashtag_flag = 1;
break;
case '-':
i = params->minus_flag = 1;
break;
case '0':
i = params->zero_flag = 1;
break;
}
return (i);
}

/**
 * get_modifier - finds the modifier func
 * @s: format string
 * @params: parameters struct
 * Return: modifier validation
*/
int get_modifier(char *s, params_t *params)
{
int i = 0;
switch (*s)
{
case 'h':
i = params->h_modifier = 1;
break;
case 'l':
i = params->l_modifier = 1;
break;
}
return (i);
}

/**
 * get_width - width from the format string
 * @s: format string
 * @ap: pointer
 * @params: parameters struct
 * Return: pointer
*/
char *get_width(char *s, va_list ap, params_t *params)
{
int d = 0;
if (*s == '*')
{
d = va_arg(ap, int);
s++;
}
else
{
while (_isdigit(*s))
d = d * 10 + (*s++ - '0');
}
params->width = d;
return (s);
}

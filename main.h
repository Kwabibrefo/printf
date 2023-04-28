#ifndef MAIN_H
#define MAIN_H
#define PRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1
#define NULL_STRING "(null)"
#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define CONVERT_LOWERCASE  1
#define CONVERT_UNSIGNED  2

int _printf(const char *format, ...);
/*_puts module*/
int _puts(char *str);
int _putchar(int c);

/* TASKs */
int char_print(va_list ap, params_t *params);
int string_print(va_list ap, params_t *params);
int percent_print(va_list ap, params_t *params);
int int_print(va_list ap, params_t *params);
int S_print(va_list ap, params_t *params);
char *convert(long int num, int base, int flags, params_t *params);
int unsigned_print(va_list ap, params_t *params);
int address_print(va_list ap, params_t *params);
int hex_print(va_list ap, params_t *params);
int HEX_print(va_list ap, params_t *params);
int binary_print(va_list ap, params_t *params);
int octal_print(va_list ap, params_t *params);

/*get_specifier.c */
int (*get_specifier(char *s))(va_list ap, params_t *params);
int get_print_func(char *s, va_list ap, params_t *params);
int get_flag(char *s, params_t *params);
int get_modifier(char *s, params_t *params);
char *get_width(char *s, va_list ap, params_t *params);

/* simple_printers.c  */
int print_from_to(char *start, char *stop, char *except)
int print_rev(va_list ap, params_t *params);
int print_rot13(va_list ap, params_t *params);

/* number_print.c */
int _isdigit(int c);
int _strlen(char *s);
int number_print(char *str, params_t *params);
int print_number_right_shift(char *str, params_t *params);
int print_number_left_shift(char *str, params_t *params);

/**
 * struct parameters - struct parameters
 * @unsign: unsigned value
 * @plus_flag: plus specified
 * @space_flag: space specified
 * @hashtag_flag: hashtage specified
 * @zero_flag: zero specified
 * @minus_flag: minus specified
 * @h_modifier: h_modifier
 * @l_modifier: l_modifier
 * @width: width specified
 * @percision: percision specified
*/
typedef struct parameters
{
unsigned int unsign :1;
unsigned int plus_flag :1;
unsigned int space_flag :1;
unsigned int hashtag_flag :1;
unsigned int zero_flag :1;
unsigned int minus_flag :1;
unsigned int h_modifier :1;
unsigned int l_modifier :1;
unsigned int width;
unsigned int percision;
} params_t;

/**
 * struct specifier - struct
 * @specifier: format token
 * @f: associated
*/
typedef struct specifier
{
char *specifier;
int (*f)(va_list, params_t *);
} specifier_t;

/* init_params.c */
void init_params(params_t *params, va_list ap);

/* string_filed.c */
char *get_precision(char *p, params_t *params, va_list ap);
#endif

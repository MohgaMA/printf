#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

#define NULL_STRING "(null)"
#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0} /*this for the flags*/

#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1

typedef struct parameters /* for flags*/
{
	unsigned int unsign		: 1;
	unsigned int plus_flag		: 1;
	unsigned int space_flag		: 1;
	unsigned int hashtag_flag	: 1;
	unsigned int zero_flag		: 1;
	unsigned int minus_flag		: 1;

	unsigned int h_modifire		: 1;
	unsigned int l_modifire		: 1;

	unsigned int width;
	unsigned int presentage;
}
params_t;

typedef struct specifire /*the specifire function*/
{
	char *specifire;
	int(*f)(va_list, params_t*);
}
specifire_t;

/* puts */
int _puts(char *str);
int _putchar(int c);

int print_char(va_list args, params_t *params);
int print_int(va_list args, params_t *params);
int print_string(va_list args, params_t *params);
int print_percent(va_list args, params_t *params);
int print_S(va_list args, params_t *params);

/* Number Functions*/
char *convert(long int num, int base, int flags, params_t *params);
int print_unsigned(va_list args, params_t *params);
int print_address(va_list args, params_t *params);

/* specifire Functions*/
int (*get_specifire(char *s))(va_list args, params_t *params);
int get_print_fun(char *s, va_list args, params_t *params);
int get_flag(char *s, params_t *params);
int get_modifire(char *s, params_t *params);
char *get_width(char *s, params_t *params, va_list args);

/* convert numbers*/
int print_hex(va_list arags, params_t *params);
int print_HEX(va_list arags, params_t *params);
int print_binary(va_list arags, params_t *params);
int print_octal(va_list arags, params_t *params);

/* custome printers*/
int print_from_to(char *start, char *stop, char *except); /*specific part*/
int print_rev(va_list args, params_t *params); /* to flip the output*/
int print_rotation(va_list args, params_t *params);

int _isdigit(int c);
int _strlen(char *s);
int print_number(char *str, params_t *params);
int print_number_right_shift(char *str, params_t *params);
int print_number_left_shift(char *str, params_t *params);

void init_params(params_t *params, va_list args);
char *get_presentage(char *p, params_t *params, va_list args);
int _printf(const char *format, ...);

#endif

#include "main.h"
/**
 * get_specifire - find the format fun
 * @s: the format string
 * Return: the number of bytes printed
 */
int (*get_specifire(char *s))(va_list args, params_t *params)
{
	specifire_t specifires[] = {
		{"c", print_char},
		{"d", print_int},
		{"i", print_string},
		{"%", print_percent},
		{"b", print_binary},
		{"o", print_octal},
		{"u", print_unsigned},
		{"x", print_hex},
		{"X", print_HEX},
		{"p", print_address},
		{"r", print_rev},
		{"R", print_rotation},
		{NULL, NULL}
	};
	int i = 0;

	while (specifires[i].specifire)
	{
		if (*s == specifires[i].specifire[0])
		{
			return (specifires[i].f);
		}
		i++;
	}
	return (NULL);
}

/**
 * get_print_fun - find the format fun
 * @s: the format string
 * @args: arguments pointer
 * @params: the parameter struct
 * Return: the of bytes printed
 */
int get_print_fun(char *s, va_list args, params_t *params)
{
	int (*f)(va_list, params_t *) = get_specifire(s);

	if (f)
		return (f(args, params));
	return (0);
}

/**
 * get_flag - find the flag fun
 * @s: the format string
 * @params: the parameters struct
 * Return: if flag was valid
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
 * get_modifire - find the modifire fun
 * @s: the format string
 * @params: the parameter struct
 * Return: if modifire was void
 */
int get_modifire(char *s, params_t *params)
{
	int i = 0;

	switch (*s)
	{
		case 'h':
			i = params->h_modifire = 1;
			break;
		case 'l':
			i = params->l_modifire = 1;
			break;
	}
	return (i);
}

/**
 * get_width - gets the width from the format string
 * @s: the format string
 * @params: the parameter struct
 * @args: the argument pointer
 * Return: new pointer
 */
char *get_width(char *s, params_t *params, va_list args)
{
	int d = 0;

	if (*s == '*')
	{
		d = va_arg(args, int);
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


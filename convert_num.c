#include "main.h"
/**
 * print_hex - print unsigned hex number in lowercase
 * @args: the argument pointer
 * @params: the parameter struct
 * Return: bytes printed
 */
int print_hex(va_list args, params_t *params)
{
	unsigned long l;
	int c = 0;
	char *str;

	if (params->l_modifire)
		l = (unsigned long)va_arg(args, unsigned long);
	else if (params->h_modifire)
		l = (unsigned short int)va_arg(args, unsigned int);
	else
		l = (unsigned int)va_arg(args, unsigned int);

	str = convert(l, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	if (params->hashtag_flag && l)
	{
		*--str = 'x';
		*--str = '0';
	}
	params->unsign = 1;
	return (c += print_number(str, params));
}

/**
 * print_HEX - print unsigned hex number in lowercase
 * @args: the argument pointer
 * @params: the parameter struct
 * Return: bytes printed
 */
int print_HEX(va_list args, params_t *params)
{
	unsigned long l;
	int c = 0;
	char *str;

	if (params->l_modifire)
		l = (unsigned long)va_arg(args, unsigned long);
	else if (params->h_modifire)
		l = (unsigned short int)va_arg(args, unsigned int);
	else
	       	l = (unsigned int)va_arg(args, unsigned int);
	str = convert(l, 16, CONVERT_UNSIGNED, params);
	if (params->hashtag_flag && l)
	{
		*--str = 'X';
		*--str = '0';
	}
	params->unsign = 1;
	return (c += print_number(str, params));
}

/**
 * print_binary - print unsigned binary num
 * @args: argument pointer
 * @params: the parameter struct
 * Return: bytes printed
 */
int print_binary(va_list args, params_t *params)
{
	unsigned int n = va_arg(args, unsigned int);
	char *str = convert(n, 2, CONVERT_UNSIGNED, params);
	int c = 0;

	if (params->hashtag_flag && n)
		*--str = '0';
	params->unsign = 1;
	return (c += print_number(str, params));
}

/**
 * print_octal - print unsigned octal num
 * @args: argument pointer
 * @params: the parameter struct
 * Return: bytes printed
 */
int print_octal(va_list args, params_t *params)
{
	unsigned long l;
	char *str;
	int c = 0;

	if (params->l_modifire)
		l = (unsigned long)va_arg(args, unsigned long);
	else if (params->h_modifire)
		l = (unsigned short int)va_arg(args, unsigned int);
	else
		l = (unsigned int)va_arg(args, unsigned int);
	str = convert(l, 8, CONVERT_UNSIGNED, params);
	
	if (params->hashtag_flag && l)
		*--str = '0';
	params->unsign = 1;
	return (c += print_number(str, params));
}


#include "main.h"
/**
 * print_char - print character
 * @args: argument pointer
 * @params: the parameter struct
 * Return: number chars printed
 */
int print_char(va_list args, params_t *params)
{
	char pad_char = ' ';
	unsigned int pad = 1, sum = 0, ch = va_arg(args, int);

	if (params->minus_flag)
		sum += _putchar(ch);
	while (pad++ < params->width)
		sum += _putchar(pad_char);
	if (!params->minus_flag)
		sum += _putchar(ch);
	return (sum);
}

/**
 * print_int - prints integer
 * @args: argument pointer
 * @params: the parameters struct
 * Return: number chars printed
 */
int print_int(va_list args, params_t *params)
{
	long l;

	if (params->l_modifire)
		l = va_arg(args, long);
	else if (params->h_modifire)
		l = (short int)va_arg(args, int);
	else
		l = (int)va_arg(args, int);
	return (print_number(convert(l, 10, 0, params), params));
}

/**
 * print_string - print string
 * @args: argument pointer
 * @params: the parameters struct
 * Return: number chars printed
 */
int print_string(va_list args, params_t *params)
{
	char *str = va_arg(args, char *), pad_char = ' ';
	unsigned int pad = 0, sum = 0, i = 0, j;

	(void)params;
	switch ((int)(!str))
		case 1:
		str = NULL_STRING;
	
	j = pad = _strlen(str);
	if (params->presentage < pad)
		j = pad = params->presentage;

	if (params->minus_flag)
	{
		if (params->presentage != UINT_MAX)
			for (i = 0; i < pad; i++)
				sum += _putchar(*str++);
		else
			sum += _puts(str);
	}
	while (j++ < params->width)
		sum += _putchar(pad_char);
	if (!params->minus_flag)
	{
		if (params->presentage !=  UINT_MAX)
			for (i = 0; i < pad; i++)
				sum += _putchar(*str++);
		else
			sum += _puts(str);
	}
	return (sum);
}

/**
 * print_percent - print percent
 * @args: argument pointer
 * @params: the parameters struct
 * Return: number chars printed
 */
int print_percent(va_list args, params_t *params)
{
	(void)args;
	(void)params;
	return (_putchar('%'));
}

/**
 * print_S - print percent
 * @args: argument pointer
 * @params: the parameters struct
 * Return: number chars printed
 */
int print_S(va_list args, params_t *params)
{
	char *str = va_arg(args, char *);
	char *hex;
	int sum = 0;

	if ((int)(!str))
		return (_puts(NULL_STRING));
	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			sum += _putchar('\\');
			sum += _putchar('x');
			hex = convert(*str, 16, 0, params);
			if (!hex[1])
				sum += _putchar('0');
			sum += _puts(hex);
		}
		else
			sum += _putchar(*str);
	}
	return (sum);
}

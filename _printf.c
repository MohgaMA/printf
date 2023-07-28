#include "main.h"
/**
 * _printf - formatted output conversion and print data.
 * @format: input string.
 *
 * Return: number of chars printed.
 */
int _printf(const char *format, ...)
{
	int sum = 0; /* we will return that at the end*/
	va_list args;
	char *p, *start; /*pointers*/
	params_t params = PARAMS_INIT; /*flags*/

	va_start(args, format);

	if(!format || (format[0] == '%' && !format[1]))/*check for the format that is not null*/
		return (-1);
	if(format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = (char *)format; *p; p++)/* loop on the format characters an *p in not null*/
	{
		init_params(&params, args);
		if (*p != '%')
		{
			sum += _putchar(*p);
			continue;
		}
		start = p;
		p++;
		while (get_flag(p, &params)) /*while char at p is flag char*/
		{
			p++; /*next char*/
		}
		p = get_width(p, &params, args);
		p = get_presentage(p, &params, args);
		if (get_modifire(p, &params))
			p++;
		if (!get_specifire(p))
			sum += print_from_to(start, p,
				params.l_modifire || params.h_modifire ? p - 1 : 0);
		else
			sum += get_print_fun(p, args, &params);
	}
	_putchar(BUF_FLUSH);
	va_end(args);
	return (sum);
}

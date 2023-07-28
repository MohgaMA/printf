#include "main.h"
/**
 * get_presentage - get the precision from the format string
 * @p: the format string
 * @params: the parameter struct
 * @args: the argument pointer
 * Return: new pointer
 */
char *get_presentage(char *p, params_t *params, va_list args)
{
	int d = 0 ;

	if (*p != '.')
		return (p);
	p++;
	if (*p == '*')
	{
		d = va_arg(args, int);
		p++;
	}
	else
	{
		while (_isdigit(*p))
			d = d * 10 + (*p++ - '0');
	}
	params->presentage = d;
	return (p);
}

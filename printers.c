#include "main.h"
/**
 * print_from_to - print a range from char address
 * @start: starting address
 * @stop: stopping address
 * @except: except address
 * Return: number bytes printed
 */
int print_from_to(char *start, char *stop, char *except)
{
	int sum = 0;

	while (start <= stop)
	{
		if (start != except)
			sum += _putchar(*start);
		start++;
	}
	return (sum);
}

/**
 * print_rev - prints string in revers
 * @args: string
 * @params: the parameters struct
 * Return: number bytes printed
 */
int print_rev(va_list args, params_t *params)
{
	int len, sum = 0;
	char *str = va_arg(args, char*);
	(void)params;
	if (str)
	{
		for (len = 0; *str; str++)
			len++;
		str--;
		for (; len > 0; len--, str--)
			sum += _putchar(*str);
	}
	return (sum);
}

/**
 * print_rotation - prints string in rot 13
 * @args: string
 * @params: parameter struct
 * Return: number bytes printed
 */
int print_rotation(va_list args, params_t *params)
{
	int i, index;
	int count = 0;
	char array[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM	nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(args, char *);
	(void)params;

	i = 0;
	index = 0;
	while (a[i])
	{
		if ((a[i] >= 'A' && a[i] <= 'Z') || (a[i] >= 'a' && a[i] <= 'z'))
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

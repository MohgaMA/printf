#include "main.h"
/**
 * init_params - clear struct field and end buf
 * @params: the parameters struct
 * @args: the argument pointer
 * Return: void
 */
void init_params(params_t *params, va_list args)
{
	params->unsign = 0;
	params->plus_flag = 0;
	params->hashtag_flag = 0;
	params->zero_flag = 0;
	params->minus_flag = 0;
	params->space_flag = 0;

	params->h_modifire = 0;
	params->l_modifire = 0;

	params->width = 0;
	params->presentage = UINT_MAX;
	(void)args;
}

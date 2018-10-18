#include "../inc/ft_printf.h"

static char			*convert_base_ux(size_t unsgnd, int base)
{
	char	*ret;
	size_t	len;
	size_t 	base_temp;
	size_t	unsgnd_temp;

	unsgnd_temp = unsgnd;
	base_temp = (size_t)base;
	len = 1;
	while (unsgnd_temp /= base_temp)
		len++;
	if (!(ret = ft_strnew(len + 1)))
		return (NULL);
	while (len--)
	{
		if (unsgnd % base < 10)
			ret[len] = (char)(unsgnd % base + '0');
		else
			ret[len] = (char)(unsgnd% base + ('A' - 10));
		unsgnd /= base;
	}
	return (ret);
}

int				handle_ux(t_handler *handler, va_list args)
{
	char	*result;
	size_t	value;
	size_t	len;

	value = va_arg(args, size_t);
	if (handler->length == HH)
		value = (unsigned char)value;
	else if (handler->length == H)
		value = (unsigned short)value;
	else if (handler->length == LL)
		value = (unsigned long long)value;
	else if (handler->length == L)
		value = (unsigned long)value;
	else if (handler->length == J)
		value = (uintmax_t)value;
	else if (handler->length == Z)
		value = (size_t)value;
	else
		value = (unsigned)value;
	result = convert_base_ux(value, 16);
	len = ft_strlen(result) * check_precision(handler->prec, &result);
	handler->hash *= value != 0;
	return (print_value(handler, result, len, false));
}

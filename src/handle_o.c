#include "../inc/ft_printf.h"

int				handle_o(t_handler *handler, va_list args)
{
	char	*result;
	size_t	value;
	size_t	len;

	value = va_arg(args, size_t);
	if (handler->length == HH)
		value = (unsigned char)value;
	else if (handler->length == H)
		value = (unsigned short)value;
	else if (handler->length == L)
		value = (unsigned long)value;
	else if (handler->length == LL)
		value = (unsigned long long)value;
	else if (handler->length == J)
		value = (uintmax_t)value;
	else if (handler->length == Z)
		value = (size_t)value;
	else
		value = (unsigned)value;
	result = convert_base_opux(value, 8);
	len = ft_strlen(result) * check_precision(handler->prec, &result);
	handler->hash *= !(value == 0 && handler->prec);
	handler->hash *= (handler->prec <= (int)len);
	return (print_value(handler, result, len, false));
}


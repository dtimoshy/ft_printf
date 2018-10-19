#include "../inc/ft_printf.h"

static int		print_prefix_o(t_handler *h)
{
	if (h->hash)
	{
		ft_putchar('0');
		return (1);
	}
	return (0);
}

static int		print_width_o(t_handler *h, size_t value_len)
{
	int chars;

	chars = 0;
	if (h->prec > (int)value_len)
		value_len += h->prec - value_len;
	value_len += h->hash;
	if (h->right)
		h->zero *= 0;
	while (h->width-- > (int)value_len)
	{
		if (h->zero)
			ft_putchar('0');
		else
			ft_putchar(' ');
		chars++;
	}
	return (chars);
}

static int		print_o(t_handler *h, char *result, size_t len)
{
	int printed;

	printed = (int)len;
	h->zero *= h->prec == -1;
	if (h->right)
	{
		printed += print_prefix_o(h);
		printed += prec_check_print(h->prec, len, 0, 1);
		ft_putstr(result);
		printed += print_width_o(h, len);
	}
	else
	{
		if (h->zero)
			printed += print_prefix_o(h);
		printed += print_width_o(h, len);
		if (!(h->zero))
			printed += print_prefix_o(h);
		printed += prec_check_print(h->prec, len, 0, 1);
		ft_putstr(result);
	}
	ft_strdel(&result);
	return (printed);
}


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
	len = ft_strlen(result) * prec_check_print(handler->prec, 0, &result, 0);
	handler->hash *= !(value == 0 && handler->prec);
	handler->hash *= (handler->prec <= (int)len);
	return (print_o(handler, result, len));
}


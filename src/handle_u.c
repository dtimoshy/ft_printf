#include "../inc/ft_printf.h"

static int	print_precision_u(int prec, size_t value_len)
{
	int chars;

	chars = 0;
	while (prec-- > (int)value_len)
	{
		ft_putchar('0');
		chars++;
	}
	return (chars);
}

static int	print_width_u(t_handler *h, size_t value_len)
{
	int chars;

	chars = 0;
	if (h->prec > (int)value_len)
		value_len += h->prec - value_len;
	if (h->pad_right)
		h->pad_zero *= 0;
	while (h->width-- > (int)value_len)
	{
		if (h->pad_zero)
			ft_putchar('0');
		else
			ft_putchar(' ');
		chars++;
	}
	return (chars);
}

static int			print_value_u(t_handler *h, char *result, size_t len)
{
	int printed;

	printed = (int)len;
	h->pad_zero *= h->prec == -1;
	if (h->pad_right)
	{
		printed += print_precision_u(h->prec, len);
		ft_putstr(result);
		printed += print_width_u(h, len);
	}
	else
	{
		printed += print_width_u(h, len);
		printed += print_precision_u(h->prec, len);
		ft_putstr(result);
	}
	ft_strdel(&result);
	return (printed);
}

int				handle_u(t_handler *handler, va_list args)
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
	result = convert_base_opux(value, 10);
	len = ft_strlen(result) * check_precision(handler->prec, &result);
	return (print_value_u(handler, result, len));
}

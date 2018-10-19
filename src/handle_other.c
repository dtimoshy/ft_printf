#include "../inc/ft_printf.h"

static int	print_precision_other(int prec, size_t value_len)
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

static int	print_width_other(t_handler *h, size_t value_len)
{
	int chars;

	chars = 0;
	if (h->prec > (int)value_len)
		value_len += h->prec - value_len;
	if (h->pad_right)
		h->pad_zero = false;
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

int			print_value_other(t_handler *h, char *result, size_t len)
{
	int printed;

	printed = (int)len;
	if (h->pad_right)
	{
		printed += print_precision_other(h->prec, len);
		ft_putstr(result);
		printed += print_width_other(h, len);
	}
	else
	{
		printed += print_width_other(h, len);
		printed += print_precision_other(h->prec, len);
		ft_putstr(result);
	}
	ft_strdel(&result);
	return (printed);
}

int					handle_other(t_handler *handler)
{
	char	*value;
	size_t	len;

	value = ft_strnew(1);
	value[0] = handler->sp;
	if (value[0] == '\0')
		len = 1;
	else
		len = ft_strlen(value);
	handler->prec = -1;
	return (print_value_other(handler, value, len));
}

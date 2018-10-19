#include "../inc/ft_printf.h"

static int	print_width_dper(t_handler *h, size_t value_len)
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

int			print_dper(t_handler *h, char *result, size_t len)
{
	int printed;

	printed = (int)len;
	if (h->pad_right)
	{
		printed += prec_check_print(h->prec, len, 0, 1);
		ft_putstr(result);
		printed += print_width_dper(h, len);
	}
	else
	{
		printed += print_width_dper(h, len);
		printed += prec_check_print(h->prec, len, 0, 1);
		ft_putstr(result);
	}
	ft_strdel(&result);
	return (printed);
}

int			handle_dper(t_handler *handler)
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
	return (print_dper(handler, value, len));
}

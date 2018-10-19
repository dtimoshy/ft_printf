
#include "../inc/ft_printf.h"

static int		print_width_c(t_handler *h, size_t value_len)
{
	int chars;

	chars = 0;
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

static int		print_char(t_handler *h, char *result, size_t len)
{
	int printed;

	printed = (int)len;
	if (h->pad_right)
	{
		printed += prec_check_print(h->prec, len, 0, 1);
		if (h->length != L)
			ft_putchar(result[0]);
		else
			ft_putstr(result);
		printed += print_width_c(h, len);
	}
	else
	{
		printed += print_width_c(h, len);
		printed += prec_check_print(h->prec, len, 0, 1);
		if (*result == '\0')
			ft_putchar('\0');
		else
			ft_putstr(result);
	}
	ft_strdel(&result);
	return (printed);
}

int				handle_char(t_handler *handler, va_list args)
{
	char	*value;
	size_t	len;

	if (handler->length == L)
		value = get_wchar(va_arg(args, wchar_t));
	else
	{
		value = ft_strnew(1);
		value[0] = (char)va_arg(args, int);
	}
	if (value[0] == '\0')
		len = 1;
	else
		len = ft_strlen(value);
	handler->prec = -1;
	return (print_char(handler, value, len));
}

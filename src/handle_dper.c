#include "../inc/ft_printf.h"

static int	print_prefix_dper(t_handler *h, bool neg_sign)
{
	if (h->hash)
	{
		if (h->sp == 'o')
			return (int)(write(1, "0", ft_strlen("0")));
		if (h->sp == 'x' || h->sp == 'X' || h->sp == 'p')
		{
			ft_putchar('0');
			ft_putchar((char)(h->sp == 'X' ? 'X' : 'x'));
			return (2);
		}
	}
	if (h->force_sign && h->sp == 'd')
		return (int)(neg_sign ? write(1, "-", ft_strlen("-"))
							: write(1, "+", ft_strlen("+")));
	else if (h->space_flag && h->sp == 'd')
		return (int)(write(1, " ", ft_strlen(" ")));
	return (0);
}

static int	print_precision_dper(int prec, size_t value_len)
{
	int chars;

	chars = 0;
	while (prec > (int)value_len)
	{
		ft_putchar('0');
		chars++;
		prec--;
	}
	return (chars);
}

static int	print_width_dper(t_handler *h, size_t value_len)
{
	int chars;

	chars = 0;
	if (h->prec > (int)value_len && h->sp != 'c')
		value_len += h->prec - value_len;
	value_len += (h->force_sign || h->space_flag)
				&& h->sp == 'd';
	value_len += h->hash && h->sp == 'o';
	value_len += ((h->sp == 'x' || h->sp == 'X' || h->sp == 'p')
				&& h->hash) * 2;
	h->pad_zero *= !(h->pad_right);
	while (h->width > (int)value_len)
	{
		ft_putchar((char)(h->pad_zero ? '0' : ' '));
		chars++;
		h->width--;
	}
	return (chars);
}

static int			print_value_dper(t_handler *h, char *result, size_t len, bool neg_sign)
{
	int printed;

	printed = (int)len;
	if (ft_strchr("duoxXp", h->sp))
		h->pad_zero *= h->prec == -1;
	if (h->pad_right)
	{
		printed += print_prefix_dper(h, neg_sign);
		printed += print_precision_dper(h->prec, len);
		h->sp == 'c' && h->length != L ? ft_putchar(result[0])
										: ft_putstr(result);
		printed += print_width_dper(h, len);
	}
	else
	{
		printed += h->pad_zero ? print_prefix_dper(h, neg_sign) : 0;
		printed += print_width_dper(h, len);
		printed += h->pad_zero ? 0 : print_prefix_dper(h, neg_sign);
		printed += print_precision_dper(h->prec, len);
		h->sp == 'c' && ft_strequ(result, "\0") ? ft_putchar(result[0])
												: ft_putstr(result);
	}
	ft_strdel(&result);
	return (printed);
}

static int			wchar_bytes_dper(wchar_t value)
{
	int res;
	int temp;

	temp = (int)value;
	if (temp == 0)
		return (1);
	res = 0;
	while (temp)
	{
		temp /= 2;
		res++;
	}
	if (res > 16 && MB_CUR_MAX >= 4)
		return (4);
	else if (res > 11 && res <= 16 && MB_CUR_MAX >= 3)
		return (3);
	else if(res > 7 && res <= 11 && MB_CUR_MAX >= 2)
		return (2);
	else
		return (1);
}

static char				*get_wchar_dper(wchar_t value)
{
	char	*ret;
	int		bytes;

	if (value == 0)
		return (ft_strdup("\0"));
	bytes = wchar_bytes_dper(value);
	ret = ft_memalloc(bytes + 1);
	if (bytes == 1)
		ret[0] = (char)value;
	else
		ret[0] = (char)(((value) & 63) + 128);
	if (bytes == 2)
		ret[1] = (char)((value >> 6) + 192);
	else if (bytes == 3)
	{
		ret[1] = (char)(((value >> 6) & 63) + 128);
		ret[2] = (char)((value >> 12) + 224);
	}
	else if (bytes == 4)
	{
		ret[1] = (char)(((value >> 6) & 63) + 128);
		ret[2] = (char)(((value >> 12) & 63) + 128);
		ret[3] = (char)((value >> 18) + 240);
	}
	return (ft_strrev((char *)ret));
}

int					handle_dper(t_handler *handler, va_list args)
{
	char	*value;
	size_t	len;

	if (handler->length == L && handler->sp == 'c')
		value = get_wchar_dper(va_arg(args, wchar_t));
	else
	{
		value = ft_strnew(1);
		if (handler->sp == 'c')
			value[0] = (char)va_arg(args, int);
		else
			value[0] = handler->sp;
	}
	if (value[0] == '\0')
		len = 1;
	else
		len = ft_strlen(value);
	handler->prec = -1;
	return (print_value_dper(handler, value, len, false));
}
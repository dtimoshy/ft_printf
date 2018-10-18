#include "../inc/ft_printf.h"

static int	print_prefix_d(t_handler *h, bool neg_sign)
{
	if (h->force_sign)
	{
		if (neg_sign)
			write(1, "-", 1);
		else
			write(1, "+", 1);
		return (1);
	}
	else if (h->space_flag)
	{
		write(1, " ", 1);
		return (1);
	}
	return (0);
}

static int	print_precision_d(int prec, size_t value_len)
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

static int	print_width_d(t_handler *h, size_t value_len)
{
	int chars;

	chars = 0;
	if (h->prec > (int)value_len)
		value_len += h->prec - value_len;
	value_len += (h->force_sign || h->space_flag);
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

static int			print_value_d(t_handler *h, char *result, size_t len, bool neg_sign)
{
	int printed;

	printed = (int)len;
	h->pad_zero *= h->prec == -1;
	if (h->pad_right)
	{
		printed += print_prefix_d(h, neg_sign);
		printed += print_precision_d(h->prec, len);
		ft_putstr(result);
		printed += print_width_d(h, len);
	}
	else
	{
		if (h->pad_zero)
			printed += print_prefix_d(h, neg_sign);
		printed += print_width_d(h, len);
		if (!(h->pad_zero))
			printed += print_prefix_d(h, neg_sign);
		printed += print_precision_d(h->prec, len);
		ft_putstr(result);
	}
	ft_strdel(&result);
	return (printed);
}

static char			*convert_base_d(size_t unsgnd, int base)
{
	char	*ret;
	size_t	len;
	ssize_t	sgnd;
	ssize_t num_temp;
	ssize_t	base_temp;

	num_temp = (ssize_t)unsgnd;
	base_temp = (ssize_t)base;
	len = 1;
	while (num_temp /= base)
		len++;
	if (!(ret = ft_strnew(len + 1)))
		return (NULL);
	sgnd = (ssize_t)unsgnd;
	while (len--)
		{
			ret[len] = (char)(ft_abs(sgnd % base) + '0');
			sgnd /= base;
		}
	return (ret);
}

int				handle_d(t_handler *h, va_list args)
{
	char		*result;
	ssize_t		value;
	size_t		len;

	value = (va_arg(args, ssize_t));
	if (h->length == HH)
		value = (signed char)value;
	else if (h->length == H)
		value = (short)value;
	else if (h->length == L)
		value = (long)value;
	else if (h->length == LL)
		value = (long long)value;
	else if (h->length == J)
		value = (intmax_t)value;
	else if (h->length == Z)
		value = (ssize_t)value;
	else
		value = (int)value;
	result = convert_base_d((size_t)value, 10);
	len = ft_strlen(result) * check_precision(h->prec, &result);
	h->force_sign = h->force_sign || value < 0;
	return (print_value_d(h, result, len, value < 0));
}
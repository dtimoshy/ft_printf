
#include "../inc/ft_printf.h"

static int		print_width_string(t_handler *h, size_t value_len)
{
	int chars;

	chars = 0;
	if (h->prec > (int)value_len)
		value_len += h->prec - value_len;
	if (h->pad_right)
		h->pad_zero = 0;
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

static int		print_string(t_handler *h, char *result, size_t len)
{
	int printed;

	printed = (int)len;
	if (h->pad_right)
	{
		printed += prec_check_print(h->prec, len, 0, 1);
		ft_putstr(result);
		printed += print_width_string(h, len);
	}
	else
	{
		printed += print_width_string(h, len);
		printed += prec_check_print(h->prec, len, 0, 1);
		ft_putstr(result);
	}
	ft_strdel(&result);
	return (printed);
}

int				handle_string(t_handler *h, va_list args)
{
	char	*value;
	char	*result;
	char	*temp;

	if (h->length != L)
	{
		value = va_arg(args, char *);
		if (value == NULL)
			result = ft_strdup("(null)");
		else
			result = ft_strdup(value);
		if (h->prec >= 0 && h->prec < (int)ft_strlen(result))
		{
			temp = ft_strnew((size_t)h->prec);
			if (temp)
				ft_strncpy(temp, result, (size_t)h->prec);
			ft_strdel(&result);
			result = temp;
		}
	}
	else
		result = get_wstr(va_arg(args, wchar_t *), h->prec);
	h->prec = -1;
	return (print_string(h, result, ft_strlen(result)));
}

// static char		*precision_cut(char *src, int prec)
// {
// 	char *dest;

// 	if (prec >= 0 && prec < (int)ft_strlen(src))
// 	{
// 		dest = ft_strnew((size_t)prec);
// 		if (dest)
// 			ft_strncpy(dest, src, (size_t)prec);
// 		ft_strdel(&src);
// 		return (dest);
// 	}
// 	else
// 		return (src);
// }

// int				handle_string(t_handler *h, va_list args)
// {
// 	char	*value;
// 	char	*result;

// 	if (h->length != L)
// 	{
// 		value = va_arg(args, char *);
// 		if (value == NULL)
// 			result = ft_strdup("(null)");
// 		else
// 			result = ft_strdup(value);
// 		result = precision_cut(result, h->prec);
// 	}
// 	else
// 		result = get_wstr(va_arg(args, wchar_t *), h->prec);
// 	h->prec = -1;
// 	return (print_string(h, result, ft_strlen(result)));
// }

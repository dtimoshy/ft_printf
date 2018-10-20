#include "../inc/ft_printf.h"

static int		print_pref_o(t_pf *pf)
{
	if (pf->hash)
	{
		ft_putchar('0');
		return (1);
	}
	return (0);
}

static int		print_wid_o(t_pf *pf, size_t value_len)
{
	int chars;

	chars = 0;
	if (pf->prec > (int)value_len)
		value_len += pf->prec - value_len;
	value_len += pf->hash;
	if (pf->right)
		pf->zero *= 0;
	while (pf->width-- > (int)value_len)
	{
		if (pf->zero)
			ft_putchar('0');
		else
			ft_putchar(' ');
		chars++;
	}
	return (chars);
}

static int		print_o(t_pf *pf, char *result, size_t len)
{
	int printed;

	printed = (int)len;
	pf->zero *= pf->prec == -1;
	if (pf->right)
	{
		printed += print_pref_o(pf);
		printed += prec_check_print(pf->prec, len, 0, 1);
		ft_putstr(result);
		printed += print_wid_o(pf, len);
	}
	else
	{
		if (pf->zero)
			printed += print_pref_o(pf);
		printed += print_wid_o(pf, len);
		if (!(pf->zero))
			printed += print_pref_o(pf);
		printed += prec_check_print(pf->prec, len, 0, 1);
		ft_putstr(result);
	}
	ft_strdel(&result);
	return (printed);
}


int				handle_o(t_pf *pf, va_list args)
{
	char	*result;
	size_t	value;
	size_t	len;

	value = va_arg(args, size_t);
	if (pf->length == HH)
		value = (unsigned char)value;
	else if (pf->length == H)
		value = (unsigned short)value;
	else if (pf->length == L)
		value = (unsigned long)value;
	else if (pf->length == LL)
		value = (unsigned long long)value;
	else if (pf->length == J)
		value = (uintmax_t)value;
	else if (pf->length == Z)
		value = (size_t)value;
	else
		value = (unsigned)value;
	result = convert_base_opux(value, 8);
	len = ft_strlen(result) * prec_check_print(pf->prec, 0, &result, 0);
	pf->hash *= !(value == 0 && pf->prec);
	pf->hash *= (pf->prec <= (int)len);
	return (print_o(pf, result, len));
}


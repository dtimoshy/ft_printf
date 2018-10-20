#include "../inc/ft_printf.h"

static int	print_wid_other(t_pf *pf, size_t value_len)
{
	int chars;

	chars = 0;
	if (pf->prec > (int)value_len)
		value_len += pf->prec - value_len;
	if (pf->right)
		pf->zero = 0;
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

int			print_other(t_pf *pf, char *result, size_t len)
{
	int printed;

	printed = (int)len;
	if (pf->right)
	{
		printed += prec_check_print(pf->prec, len, 0, 1);
		ft_putstr(result);
		printed += print_wid_other(pf, len);
	}
	else
	{
		printed += print_wid_other(pf, len);
		printed += prec_check_print(pf->prec, len, 0, 1);
		ft_putstr(result);
	}
	ft_strdel(&result);
	return (printed);
}

int			handle_other(t_pf *pf)
{
	char	*value;
	size_t	len;

	value = ft_strnew(1);
	value[0] = pf->spec;
	if (value[0] == '\0')
		len = 1;
	else
		len = ft_strlen(value);
	pf->prec = -1;
	return (print_other(pf, value, len));
}

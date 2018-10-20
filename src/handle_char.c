
#include "../inc/ft_printf.h"

static int		print_wid_c(t_pf *pf, size_t len)
{
	int chars;

	chars = 0;
	if (pf->right)
		pf->zero = 0;
	while (pf->width-- > (int)len)
	{
		if (pf->zero)
			ft_putchar('0');
		else
			ft_putchar(' ');
		chars++;
	}
	return (chars);
}

static int		print_char(t_pf *pf, char *result, size_t len)
{
	int printed;

	printed = (int)len;
	if (pf->right)
	{
		printed += prec_check_print(pf->prec, len, 0, 1);
		if (pf->length != L)
			ft_putchar(result[0]);
		else
			ft_putstr(result);
		printed += print_wid_c(pf, len);
	}
	else
	{
		printed += print_wid_c(pf, len);
		printed += prec_check_print(pf->prec, len, 0, 1);
		if (*result == '\0')
			ft_putchar('\0');
		else
			ft_putstr(result);
	}
	ft_strdel(&result);
	return (printed);
}

int				handle_char(t_pf *pf, va_list args)
{
	char	*val;
	size_t	len;

	if (pf->length == L)
		val = wchar_get(va_arg(args, wchar_t));
	else
	{
		val = ft_strnew(1);
		val[0] = (char)va_arg(args, int);
	}
	if (val[0] == '\0')
		len = 1;
	else
		len = ft_strlen(val);
	pf->prec = -1;
	return (print_char(pf, val, len));
}

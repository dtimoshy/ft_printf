
#include "../inc/ft_printf.h"

void	spec_parse(const char **fmt, t_pf *pf)
{
	if (ft_strchr("DOUCSp", **fmt))
	{
		pf->length = L;
		if (**fmt == 'D')
			pf->spec = 'd';
		else if (**fmt == 'O')
			pf->spec = 'o';
		else if (**fmt == 'U')
			pf->spec = 'u';
		else if (**fmt == 'C')
			pf->spec = 'c';
		else if (**fmt == 'S')
			pf->spec = 's';
		else
			pf->spec = 'p';
	}
	else if (**fmt == 'i')
		pf->spec = 'd';
	else
		pf->spec = **fmt;
	(*fmt)++;
}

void	len_parse(const char **fmt, t_pf *pf)
{
	if (**fmt == 'h' && *(*fmt + 1) == 'h')
	{
		pf->length = HH;
		*fmt += 2;
	}
	else if (**fmt == 'l' && *(*fmt + 1) == 'l')
	{
		pf->length = LL;
		*fmt += 2;
	}
	else if (ft_strchr("lhjz", (**fmt)))
	{
		if (**fmt == 'h' && (H - pf->length) >= 0)
				pf->length = H;
		else if (**fmt == 'l' && (L - pf->length) >= 0)
				pf->length = L;
		else if (**fmt == 'j')
			pf->length = J;
		else if (**fmt == 'z')
			pf->length = Z;
		(*fmt)++;
	}
}

int			num_convert(t_pf *pf, va_list args)
{
	int res;

	res = 0;
	if (pf->spec == 'd')
		res = handle_d(pf, args);
	else if (pf->spec == 'u')
		res = handle_u(pf, args);
	else if (pf->spec == 'o')
		res = handle_o(pf, args);
	else if (pf->spec == 'x')
		res = handle_x(pf, args);
	else if (pf->spec == 'p')
		res = handle_p(pf, args);
	else if (pf->spec == 'X')
		res = handle_bx(pf, args);
	return (res);
}

int			char_convert(t_pf *pf, va_list args)
{
	int res;

	res = 0;
	if (pf->spec == 's')
		res = handle_string(pf, args);
	else if (pf->spec == 'c')
		res = handle_char(pf, args);
	else if (pf->spec == '%' || !ft_strchr("duoxXpc%", pf->spec))
		res = handle_other(pf);
	return (res);
}

#include "../inc/ft_printf.h"

char			*convert_base_bx(size_t unsgnd, int base)
{
	char	*ret;
	size_t	len;
	size_t 	base_temp;
	size_t	unsgnd_temp;

	unsgnd_temp = unsgnd;
	base_temp = (size_t)base;
	len = 1;
	while (unsgnd_temp /= base_temp)
		len++;
	if (!(ret = ft_strnew(len + 1)))
		return (NULL);
	while (len--)
	{
		if (unsgnd % base < 10)
			ret[len] = (char)(unsgnd % base + '0');
		else
			ret[len] = (char)(unsgnd% base + ('A' - 10));
		unsgnd /= base;
	}
	return (ret);
}

char			*convert_base_d(size_t unsgnd, int base)
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

char			*convert_base_opux(size_t unsgnd, int base)
{
	char	*ret;
	size_t	len;
	size_t 	base_temp;
	size_t	unsgnd_temp;

	unsgnd_temp = unsgnd;
	base_temp = (size_t)base;
	len = 1;
	while (unsgnd_temp /= base_temp)
		len++;
	if (!(ret = ft_strnew(len + 1)))
		return (NULL);
	while (len--)
	{
		if (unsgnd % base < 10)
			ret[len] = (char)(unsgnd % base + '0');
		else
			ret[len] = (char)(unsgnd% base + ('a' - 10));
		unsgnd /= base;
	}
	return (ret);
}

int				prec_check_print(int prec, size_t len, char **s, int mode)
{
	int chars;

	if (mode == 0)
	{
		if ((size_t)prec == 0 && **s == '0')
		{
			ft_strdel(s);
			return (0);
		}
		return (1);
	}
	else if (mode == 1)
	{
		chars = 0;
		while (prec-- > (int)len)
		{
			ft_putchar('0');
			chars++;
		}
		return (chars);
	}
	return (0);
}

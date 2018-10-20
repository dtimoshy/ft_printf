/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimoshy <dtimoshy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 13:34:34 by dtimoshy          #+#    #+#             */
/*   Updated: 2018/10/20 13:34:35 by dtimoshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char			*convert_base_bx(size_t nbr, int base)
{
	char	*ret;
	size_t	len;
	size_t	base_temp;
	size_t	temp;

	temp = nbr;
	base_temp = (size_t)base;
	len = 1;
	while (temp /= base_temp)
		len++;
	if (!(ret = ft_strnew(len + 1)))
		return (NULL);
	while (len--)
	{
		if (nbr % base < 10)
			ret[len] = (char)(nbr % base + '0');
		else
			ret[len] = (char)(nbr % base + ('A' - 10));
		nbr /= base;
	}
	return (ret);
}

char			*convert_base_d(size_t nbr, int base)
{
	char	*ret;
	size_t	len;
	ssize_t	snbr;
	ssize_t temp;
	ssize_t	base_temp;

	temp = (ssize_t)nbr;
	base_temp = (ssize_t)base;
	len = 1;
	while (temp /= base)
		len++;
	if (!(ret = ft_strnew(len + 1)))
		return (NULL);
	snbr = (ssize_t)nbr;
	while (len--)
	{
		ret[len] = (char)(ft_abs(snbr % base) + '0');
		snbr /= base;
	}
	return (ret);
}

char			*convert_base_opux(size_t nbr, int base)
{
	char	*ret;
	size_t	len;
	size_t	base_temp;
	size_t	temp;

	temp = nbr;
	base_temp = (size_t)base;
	len = 1;
	while (temp /= base_temp)
		len++;
	if (!(ret = ft_strnew(len + 1)))
		return (NULL);
	while (len--)
	{
		if (nbr % base < 10)
			ret[len] = (char)(nbr % base + '0');
		else
			ret[len] = (char)(nbr % base + ('a' - 10));
		nbr /= base;
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

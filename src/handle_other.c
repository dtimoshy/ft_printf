/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_other.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimoshy <dtimoshy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 13:33:47 by dtimoshy          #+#    #+#             */
/*   Updated: 2018/10/20 13:33:48 by dtimoshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int chars;

	chars = (int)len;
	if (pf->right)
	{
		chars += prec_check_print(pf->prec, len, 0, 1);
		ft_putstr(result);
		chars += print_wid_other(pf, len);
	}
	else
	{
		chars += print_wid_other(pf, len);
		chars += prec_check_print(pf->prec, len, 0, 1);
		ft_putstr(result);
	}
	ft_strdel(&result);
	return (chars);
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

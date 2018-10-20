/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimoshy <dtimoshy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 13:33:27 by dtimoshy          #+#    #+#             */
/*   Updated: 2018/10/20 13:33:29 by dtimoshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int	print_pref_d(t_pf *pf, int neg_sign)
{
	if (pf->sign)
	{
		if (neg_sign)
			ft_putchar('-');
		else
			ft_putchar('+');
		return (1);
	}
	else if (pf->space)
	{
		ft_putchar(' ');
		return (1);
	}
	return (0);
}

static int	print_wid_d(t_pf *pf, size_t value_len)
{
	int chars;

	chars = 0;
	if (pf->prec > (int)value_len)
		value_len += pf->prec - value_len;
	value_len += (pf->sign || pf->space);
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

static int	print_d(t_pf *pf, char *result, size_t len, int neg_sign)
{
	int chars;

	chars = (int)len;
	pf->zero *= pf->prec == -1;
	if (pf->right)
	{
		chars += print_pref_d(pf, neg_sign);
		chars += prec_check_print(pf->prec, len, 0, 1);
		ft_putstr(result);
		chars += print_wid_d(pf, len);
	}
	else
	{
		if (pf->zero)
			chars += print_pref_d(pf, neg_sign);
		chars += print_wid_d(pf, len);
		if (!(pf->zero))
			chars += print_pref_d(pf, neg_sign);
		chars += prec_check_print(pf->prec, len, 0, 1);
		ft_putstr(result);
	}
	ft_strdel(&result);
	return (chars);
}

int			handle_d(t_pf *pf, va_list args)
{
	char		*result;
	ssize_t		value;
	size_t		len;

	value = (va_arg(args, ssize_t));
	if (pf->len == HH)
		value = (signed char)value;
	else if (pf->len == H)
		value = (short)value;
	else if (pf->len == L)
		value = (long)value;
	else if (pf->len == LL)
		value = (long long)value;
	else if (pf->len == J)
		value = (intmax_t)value;
	else if (pf->len == Z)
		value = (ssize_t)value;
	else
		value = (int)value;
	result = convert_base_d((size_t)value, 10);
	len = ft_strlen(result) * prec_check_print(pf->prec, 0, &result, 0);
	pf->sign = pf->sign || value < 0;
	return (print_d(pf, result, len, value < 0));
}

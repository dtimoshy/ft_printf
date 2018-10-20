/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimoshy <dtimoshy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 13:33:08 by dtimoshy          #+#    #+#             */
/*   Updated: 2018/10/20 13:33:09 by dtimoshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int chars;

	chars = (int)len;
	if (pf->right)
	{
		chars += prec_check_print(pf->prec, len, 0, 1);
		if (pf->len != L)
			ft_putchar(result[0]);
		else
			ft_putstr(result);
		chars += print_wid_c(pf, len);
	}
	else
	{
		chars += print_wid_c(pf, len);
		chars += prec_check_print(pf->prec, len, 0, 1);
		if (*result == '\0')
			ft_putchar('\0');
		else
			ft_putstr(result);
	}
	ft_strdel(&result);
	return (chars);
}

int				handle_char(t_pf *pf, va_list args)
{
	char	*val;
	size_t	len;

	if (pf->len == L)
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

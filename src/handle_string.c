/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimoshy <dtimoshy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 13:34:04 by dtimoshy          #+#    #+#             */
/*   Updated: 2018/10/20 13:34:05 by dtimoshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int		print_wid_string(t_pf *pf, size_t len)
{
	int chars;

	chars = 0;
	if (pf->prec > (int)len)
		len += pf->prec - len;
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

static int		print_string(t_pf *pf, char *result, size_t len)
{
	int chars;

	chars = (int)len;
	if (pf->right)
	{
		chars += prec_check_print(pf->prec, len, 0, 1);
		ft_putstr(result);
		chars += print_wid_string(pf, len);
	}
	else
	{
		chars += print_wid_string(pf, len);
		chars += prec_check_print(pf->prec, len, 0, 1);
		ft_putstr(result);
	}
	ft_strdel(&result);
	return (chars);
}

int				handle_string(t_pf *pf, va_list args)
{
	char	*val;
	char	*result;
	char	*temp;

	if (pf->len != L)
	{
		val = va_arg(args, char *);
		if (val == NULL)
			result = ft_strdup("(null)");
		else
			result = ft_strdup(val);
		if (pf->prec >= 0 && pf->prec < (int)ft_strlen(result))
		{
			temp = ft_strnew((size_t)pf->prec);
			if (temp)
				ft_strncpy(temp, result, (size_t)pf->prec);
			ft_strdel(&result);
			result = temp;
		}
	}
	else
		result = wstr_get(va_arg(args, wchar_t *), pf->prec);
	pf->prec = -1;
	return (print_string(pf, result, ft_strlen(result)));
}

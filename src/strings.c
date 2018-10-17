/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimoshy <dtimoshy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 17:58:06 by dtimoshy          #+#    #+#             */
/*   Updated: 2018/10/17 17:58:08 by dtimoshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static char	*get_wstr(wchar_t *value, int prec)
{
	char *res;
	char *wchar;

	if (value == NULL)
		return (ft_strdup("(null)"));
	res = ft_strnew(0);
	while (*value)
	{
		wchar = get_wchar(*value);
		if (prec != -1 && prec < (int)(ft_strlen(wchar) + ft_strlen(res)))
		{
			ft_strdel(&wchar);
			break ;
		}
		res = printf_strjoin(res, wchar);
		value++;
	}
	return (res);
}

char		*precision_cut(char *src, int prec)
{
	char *dest;

	if (prec >= 0 && prec < (int)ft_strlen(src))
	{
		dest = ft_strnew((size_t)prec);
		if (dest)
			ft_strncpy(dest, src, (size_t)prec);
		ft_strdel(&src);
		return (dest);
	}
	else
		return (src);
}

int			print_string(t_handler *h, va_list args)
{
	char	*value;
	char	*result;

	if (h->length == L && h->sp == 's')
		result = get_wstr(va_arg(args, wchar_t *), h->prec);
	else
	{
		value = va_arg(args, char *);
		result = ft_strdup(value == NULL ? "(null)" : value);
	}
	if (h->sp == 's' && h->length != L)
		result = precision_cut(result, h->prec);
	h->prec = -1;
	return (print_value(h, result, ft_strlen(result), false));
}

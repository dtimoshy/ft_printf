/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chars.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimoshy <dtimoshy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 17:57:28 by dtimoshy          #+#    #+#             */
/*   Updated: 2018/10/17 17:57:30 by dtimoshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int			wchar_bytes(wchar_t value)
{
	int res;
	int temp;

	temp = (int)value;
	if (temp == 0)
		return (1);
	res = 0;
	while (temp)
	{
		temp /= 2;
		res++;
	}
	if (res > 16 && MB_CUR_MAX >= 4)
		return (4);
	else if (res > 11 && res <= 16 && MB_CUR_MAX >= 3)
		return (3);
	else if(res > 7 && res <= 11 && MB_CUR_MAX >= 2)
		return (2);
	else
		return (1);
}

char				*get_wchar(wchar_t value)
{
	char	*ret;
	int		bytes;

	if (value == 0)
		return (ft_strdup("\0"));
	bytes = wchar_bytes(value);
	ret = ft_memalloc(bytes + 1);
	if (bytes == 1)
		ret[0] = (char)value;
	else
		ret[0] = (char)(((value) & 63) + 128);
	if (bytes == 2)
		ret[1] = (char)((value >> 6) + 192);
	else if (bytes == 3)
	{
		ret[1] = (char)(((value >> 6) & 63) + 128);
		ret[2] = (char)((value >> 12) + 224);
	}
	else if (bytes == 4)
	{
		ret[1] = (char)(((value >> 6) & 63) + 128);
		ret[2] = (char)(((value >> 12) & 63) + 128);
		ret[3] = (char)((value >> 18) + 240);
	}
	return (ft_strrev((char *)ret));
}

int					print_char(t_handler *handler, va_list args)
{
	char	*value;
	size_t	len;

	if (handler->length == L && handler->sp == 'c')
		value = get_wchar(va_arg(args, wchar_t));
	else
	{
		value = ft_strnew(1);
		if (handler->sp == 'c')
			value[0] = (char)va_arg(args, int);
		else
			value[0] = handler->sp;
	}
	if (value[0] == '\0')
		len = 1;
	else
		len = ft_strlen(value);
	handler->prec = -1;
	return (print_value(handler, value, len, false));
}

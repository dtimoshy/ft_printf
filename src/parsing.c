/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimoshy <dtimoshy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 17:57:51 by dtimoshy          #+#    #+#             */
/*   Updated: 2018/10/17 17:57:53 by dtimoshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	parse_length(const char **fmt, t_handler *handler)
{
	if (**fmt == 'h' && *(*fmt + 1) == 'h')
	{
		if ((int)(HH - handler->length) > 0)
			handler->length = HH;
		*fmt += 2;
	}
	else if (**fmt == 'l' && *(*fmt + 1) == 'l')
	{
		if ((int)(LL - handler->length) > 0)
			handler->length = LL;
		*fmt += 2;
	}
	else if (ft_strchr("lhjz", (**fmt)))
	{
		if (**fmt == 'h' && (int)(H - handler->length) >= 0)
			if (handler->length == H)
				handler->length = HH;
			else
				handler->length = H;
		else if (**fmt == 'l' && (int)(L - handler->length) >= 0)
			if (handler->length == L)
				handler->length = LL;
			else
				handler->length = L;
		else if (**fmt == 'j' && (int)(J - handler->length) > 0)
			handler->length = J;
		else if (**fmt == 'z' && (int)(Z - handler->length) > 0)
			handler->length = Z;
		(*fmt)++;
	}
}

/*
void	parse_length(const char **fmt, t_handler *handler)
{
	if (**fmt == 'h' && *(*fmt + 1) == 'h')
	{
		if ((int)(HH - handler->length) > 0)
			handler->length = HH;
		*fmt += 2;
	}
	else if (**fmt == 'l' && *(*fmt + 1) == 'l')
	{
		if ((int)(LL - handler->length) > 0)
			handler->length = LL;
		*fmt += 2;
	}
	else if (SIZE(**fmt))
	{
		if (**fmt == 'h' && (int)(H - handler->length) >= 0)
			handler->length = handler->length == H ? HH : H;
		else if (**fmt == 'l' && (int)(L - handler->length) >= 0)
			handler->length = handler->length == L ? LL : L;
		else if (**fmt == 'j' && (int)(J - handler->length) > 0)
			handler->length = J;
		else if (**fmt == 'z' && (int)(Z - handler->length) > 0)
			handler->length = Z;
		(*fmt)++;
	}
}
*/

void	parse_specifier(const char **fmt, t_handler *handler)
{
	if (ft_strchr("DOUCSp", **fmt))
	{
		handler->length = L;
		handler->sp = (char)ft_tolower(**fmt);
	}
	else if (**fmt == 'i')
		handler->sp = 'd';
	else
		handler->sp = **fmt;
	(*fmt)++;
}

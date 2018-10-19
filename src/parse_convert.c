/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimoshy <dtimoshy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 17:57:59 by dtimoshy          #+#    #+#             */
/*   Updated: 2018/10/17 17:58:00 by dtimoshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	parse_specifier(const char **fmt, t_handler *handler)
{
	if (ft_strchr("DOUCSp", **fmt))
	{
		handler->length = L;
		if (**fmt == 'D')
			handler->spec = 'd';
		else if (**fmt == 'O')
			handler->spec = 'o';
		else if (**fmt == 'U')
			handler->spec = 'u';
		else if (**fmt == 'C')
			handler->spec = 'c';
		else if (**fmt == 'S')
			handler->spec = 's';
		else
			handler->spec = 'p';
	}
	else if (**fmt == 'i')
		handler->spec = 'd';
	else
		handler->spec = **fmt;
	(*fmt)++;
}

void	parse_length(const char **fmt, t_handler *handler)
{
	if (**fmt == 'h' && *(*fmt + 1) == 'h')
	{
		handler->length = HH;
		*fmt += 2;
	}
	else if (**fmt == 'l' && *(*fmt + 1) == 'l')
	{
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
		else if (**fmt == 'j')
			handler->length = J;
		else if (**fmt == 'z')
			handler->length = Z;
		(*fmt)++;
	}
}

// void	parse_length(const char **fmt, t_handler *handler)
// {
// 	if (**fmt == 'h' && *(*fmt + 1) == 'h')
// 	{
// 		if ((int)(HH - handler->length) > 0)
// 			handler->length = HH;
// 		*fmt += 2;
// 	}
// 	else if (**fmt == 'l' && *(*fmt + 1) == 'l')
// 	{
// 		if ((int)(LL - handler->length) > 0)
// 			handler->length = LL;
// 		*fmt += 2;
// 	}
// 	else if (ft_strchr("lhjz", (**fmt)))
// 	{
// 		if (**fmt == 'h' && (int)(H - handler->length) >= 0)
// 			if (handler->length == H)
// 				handler->length = HH;
// 			else
// 				handler->length = H;
// 		else if (**fmt == 'l' && (int)(L - handler->length) >= 0)
// 			if (handler->length == L)
// 				handler->length = LL;
// 			else
// 				handler->length = L;
// 		else if (**fmt == 'j' && (int)(J - handler->length) > 0)
// 			handler->length = J;
// 		else if (**fmt == 'z' && (int)(Z - handler->length) > 0)
// 			handler->length = Z;
// 		(*fmt)++;
// 	}
// }

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

int			num_conversion(t_handler *h, va_list args)
{
	int res;

	res = 0;
	if (h->spec == 'd')
		res = handle_d(h, args);
	else if (h->spec == 'u')
		res = handle_u(h, args);
	else if (h->spec == 'o')
		res = handle_o(h, args);
	else if (h->spec == 'x')
		res = handle_x(h, args);
	else if (h->spec == 'p')
		res = handle_p(h, args);
	else if (h->spec == 'X')
		res = handle_bx(h, args);
	return (res);
}

int			char_conversion(t_handler *h, va_list args)
{
	int res;

	res = 0;
	if (h->spec == 's')
		res = handle_string(h, args);
	else if (h->spec == 'c')
		res = handle_char(h, args);
	else if (h->spec == '%' || !ft_strchr("duoxXpc%", h->spec))
		res = handle_other(h);
	return (res);
}
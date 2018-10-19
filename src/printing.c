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

static int	print_prefix(t_handler *h, bool neg_sign)
{
	if (h->hash)
	{
		if (h->sp == 'o')
			return (int)(write(1, "0", ft_strlen("0")));
		if (h->sp == 'x' || h->sp == 'X' || h->sp == 'p')
		{
			ft_putchar('0');
			ft_putchar((char)(h->sp == 'X' ? 'X' : 'x'));
			return (2);
		}
	}
	if (h->force_sign && h->sp == 'd')
		return (int)(neg_sign ? write(1, "-", ft_strlen("-"))
							: write(1, "+", ft_strlen("+")));
	else if (h->space_flag && h->sp == 'd')
		return (int)(write(1, " ", ft_strlen(" ")));
	return (0);
}

static int	print_precision(int prec, size_t value_len)
{
	int chars;

	chars = 0;
	while (prec > (int)value_len)
	{
		ft_putchar('0');
		chars++;
		prec--;
	}
	return (chars);
}

static int	print_width(t_handler *h, size_t value_len)
{
	int chars;

	chars = 0;
	if (h->prec > (int)value_len && h->sp != 'c')
		value_len += h->prec - value_len;
	value_len += (h->force_sign || h->space_flag)
				&& h->sp == 'd';
	value_len += h->hash && h->sp == 'o';
	value_len += ((h->sp == 'x' || h->sp == 'X' || h->sp == 'p')
				&& h->hash) * 2;
	h->pad_zero *= !(h->pad_right);
	while (h->width > (int)value_len)
	{
		ft_putchar((char)(h->pad_zero ? '0' : ' '));
		chars++;
		h->width--;
	}
	return (chars);
}

int			print_value(t_handler *h, char *result, size_t len, bool neg_sign)
{
	int printed;

	printed = (int)len;
	if (ft_strchr("duoxXp", h->sp))
		h->pad_zero *= h->prec == -1;
	if (h->pad_right)
	{
		printed += print_prefix(h, neg_sign);
		printed += print_precision(h->prec, len);
		h->sp == 'c' && h->length != L ? ft_putchar(result[0])
										: ft_putstr(result);
		printed += print_width(h, len);
	}
	else
	{
		printed += h->pad_zero ? print_prefix(h, neg_sign) : 0;
		printed += print_width(h, len);
		printed += h->pad_zero ? 0 : print_prefix(h, neg_sign);
		printed += print_precision(h->prec, len);
		h->sp == 'c' && ft_strequ(result, "\0") ? ft_putchar(result[0])
												: ft_putstr(result);
	}
	ft_strdel(&result);
	return (printed);
}

int			num_conversion(t_handler *h, va_list args)
{
	int res;

	res = 0;
	if (h->sp == 'd')
		res = handle_d(h, args);
	else if (h->sp == 'u')
		res = handle_u(h, args);
	else if (h->sp == 'o')
		res = handle_o(h, args);
	else if (h->sp == 'x')
		res = handle_x(h, args);
	else if (h->sp == 'p')
		res = handle_p(h, args);
	else if (ft_strchr("X", h->sp))
		res = handle_bx(h, args);
	return (res);
}

int			char_conversion(t_handler *h, va_list args)
{
	int res;

	res = 0;
	if (h->sp == 's')
		res = handle_string(h, args);
	else if (h->sp == 'c')
		res = handle_char(h, args);
	else if (h->sp == '%')
		res = handle_dper(h);
	else if (!ft_strchr("duoxXpc%", h->sp))
		res = handle_other(h);
	return (res);
}
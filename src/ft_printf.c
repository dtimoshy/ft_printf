/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimoshy <dtimoshy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 15:32:50 by dtimoshy          #+#    #+#             */
/*   Updated: 2018/10/17 15:32:52 by dtimoshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void				parse_flags(const char **fmt, t_handler *handler)
{
	if ((**fmt == ' '))
		handler->space_flag = true;
	if (**fmt == '#')
		handler->hash = true;
	if (**fmt == '-')
		handler->pad_right = true;
	if (**fmt == '0')
		handler->pad_zero = true;
	if (**fmt == '+')
		handler->force_sign = true;
	(*fmt)++;
}

void				parse_precision(const char **fmt, t_handler *handler)
{
	if (ft_isdigit(**fmt))
	{
		handler->prec = ft_atoi(*fmt);
		if (handler->prec < 0)
			*fmt += ft_nbrlen(handler->prec) + 1;
		else
			*fmt += ft_nbrlen(handler->prec);
	}
	else
		handler->prec = 0;
}

static int			parse_to_handler(const char **fmt, t_handler *handler)
{
	while ((ft_isdigit(**fmt) || ft_strchr("+- 0#lhzj", (**fmt)) ||
			**fmt == '.') && **fmt)
	{
		while (**fmt && ft_strchr("+- 0#", (**fmt)))
			parse_flags(fmt, handler);
		if (**fmt && **fmt == '.')
		{
			++*fmt;
			while (**fmt == '0')
				++*fmt;
			parse_precision(fmt, handler);
		}
		if (**fmt && ft_isdigit(**fmt))
		{
			handler->width = ft_atoi(*fmt);
			*fmt += ft_nbrlen(handler->width);
		}
		if (**fmt && ft_strchr("lhjz", (**fmt)))
			parse_length(fmt, handler);
	}
	if (**fmt)
		parse_specifier(fmt, handler);
	else
		return (0);
	return (1);
}

static int			convert_specifier(const char **format, va_list arg)
{
	t_handler	*handler;
	int			chars_printed;

	handler = (t_handler *)malloc(sizeof(t_handler));
	handler->width = 0;
	handler->prec = -1;
	handler->length = NONE;
	handler->hash = false;
	handler->pad_zero = false;
	handler->force_sign = false;
	handler->pad_right = false;
	handler->space_flag = false;
	if (parse_to_handler(format, handler) == 0)
		return (0);
	chars_printed = print_conversion(handler, arg);
	ft_memdel((void **)&handler);
	return (chars_printed);
}

int					ft_printf(const char *format, ...)
{
	va_list	arg;
	int		result;

	result = 0;
	va_start(arg, format);
	while (*format)
		if (*format == '%')
		{
			++format;
			result = result + convert_specifier(&format, arg);
		}
		else
		{
			ft_putchar(*format);
			result++;
			format++;
		}
	va_end(arg);
	return (result);
}

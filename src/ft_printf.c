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

void				prec_parse(const char **fmt, t_pf *pf)
{
	if (**fmt >= '0' && **fmt <= '9')
	{
		pf->prec = ft_atoi(*fmt);
		if (pf->prec < 0)
			*fmt += ft_nbrlen(pf->prec) + 1;
		else
			*fmt += ft_nbrlen(pf->prec);
	}
	else
		pf->prec = 0;
}

void				flag_parse(const char **fmt, t_pf *pf)
{
	if ((**fmt == ' '))
		pf->space = 1;
	else if (**fmt == '#')
		pf->hash = 1;
	else if (**fmt == '-')
		pf->right = 1;
	else if (**fmt == '0')
		pf->zero = 1;
	else if (**fmt == '+')
		pf->sign = 1;
}

static int			parse_to_pf(const char **fmt, t_pf *pf)
{
	while (ft_strchr("+- 0123456789#lhzj.", (**fmt)) && **fmt)
	{
		while (**fmt && ft_strchr("+- 0#", (**fmt)))
		{
			flag_parse(fmt, pf);
			(*fmt)++;
		}
		if (**fmt == '.')
		{
			(*fmt)++;
			while (**fmt == '0')
				(*fmt)++;
			prec_parse(fmt, pf);
		}
		if (**fmt >= '0' && **fmt <= '9')
		{
			pf->width = ft_atoi(*fmt);
			*fmt += ft_nbrlen(pf->width);
		}
		if (**fmt && ft_strchr("lhjz", (**fmt)))
			len_parse(fmt, pf);
	}
	if (**fmt)
		return (1);
	return (0);
}

static int			manage_spec(const char **format, va_list arg)
{
	t_pf		*pf;
	int			count;
	int			temp;

	pf = (t_pf *)malloc(sizeof(t_pf));
	pf->hash = 0;
	pf->zero = 0;
	pf->sign = 0;
	pf->right = 0;
	pf->space = 0;
	pf->width = 0;
	pf->prec = -1;
	pf->len = NO;
	temp = parse_to_pf(format, pf);
	if (temp == 0)
		return (0);
	spec_parse(format, pf);
	count = num_convert(pf, arg);
	count += char_convert(pf, arg);
	ft_memdel((void **)&pf);
	return (count);
}

int					ft_printf(const char *format, ...)
{
	va_list	arg;
	int		result;

	result = 0;
	va_start(arg, format);
	while (*format)
		if (*format != '%')
		{
			ft_putchar(*format);
			result++;
			format++;
		}
		else
		{
			++format;
			result = result + manage_spec(&format, arg);
		}
	va_end(arg);
	return (result);
}

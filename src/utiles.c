/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimoshy <dtimoshy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 17:58:16 by dtimoshy          #+#    #+#             */
/*   Updated: 2018/10/17 17:58:18 by dtimoshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

size_t			get_numlen(size_t usigned_num, int base, bool is_unsigned)
{
	size_t	len;
	ssize_t	signed_num;

	len = 1;
	if (is_unsigned)
		while (usigned_num /= base)
			len++;
	else
	{
		signed_num = (ssize_t)usigned_num;
		while (signed_num /= base)
			len++;
	}
	return (len);
}

char			*convert_base(size_t unsgnd, int base,
							bool upper_case, bool is_unsigned)
{
	char	*ret;
	size_t	len;
	char	a;
	ssize_t	sgnd;

	a = (char)(upper_case ? 'A' : 'a');
	len = get_numlen(unsgnd, base, is_unsigned);
	if (!(ret = ft_strnew(len + 1)))
		return (NULL);
	sgnd = (ssize_t)unsgnd;
	if (is_unsigned)
		while (len--)
		{
			ret[len] = (char)(unsgnd % base +
								(unsgnd % base < 10 ? '0' : a - 10));
			unsgnd /= base;
		}
	else
		while (len--)
		{
			ret[len] = (char)(ft_abs(sgnd % base) + '0');
			sgnd /= base;
		}
	return (ret);
}

bool			check_val_prec(int prec, char **result)
{
	if (prec == 0 && ft_strequ(*result, "0"))
	{
		ft_strdel(result);
		return (false);
	}
	return (true);
}

/*
** the same as strjoin but no leaks (accepting only malloced)
*/

char			*printf_strjoin(char *s1, char *s2)
{
	char *ret;

	if (!(s1 && s2))
		return (NULL);
	if ((ret = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		ret = ft_strcat(ft_strcat(ret, s1), s2);
	ft_strdel(&s1);
	ft_strdel(&s2);
	return (ret);
}

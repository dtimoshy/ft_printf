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

char			*convert_base_opux(size_t unsgnd, int base)
{
	char	*ret;
	size_t	len;
	size_t 	base_temp;
	size_t	unsgnd_temp;

	unsgnd_temp = unsgnd;
	base_temp = (size_t)base;
	len = 1;
	while (unsgnd_temp /= base_temp)
		len++;
	if (!(ret = ft_strnew(len + 1)))
		return (NULL);
	while (len--)
	{
		if (unsgnd % base < 10)
			ret[len] = (char)(unsgnd % base + '0');
		else
			ret[len] = (char)(unsgnd% base + ('a' - 10));
		unsgnd /= base;
	}
	return (ret);
}

bool			check_precision(int prec, char **result)
{
	if ((size_t)prec == 0 && **result == '0')
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

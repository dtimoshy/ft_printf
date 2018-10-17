/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimoshy <dtimoshy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 15:32:17 by dtimoshy          #+#    #+#             */
/*   Updated: 2018/10/17 15:32:21 by dtimoshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(int n, int base)
{
	char	*ret;
	size_t	neg;
	size_t	len;
	int		i;

	neg = (n < 0) ? 1 : 0;
	len = ft_nbrlen(n) + neg;
	if (!(ret = ft_strnew(len)) || base < 2 || base > 16)
		return (NULL);
	i = 0;
	if (n == 0)
		ret[i] = '0';
	while (n)
	{
		if (n % base < 10)
			ret[i] = ft_abs(n % base) + 48;
		else
			ret[i] = ft_abs(n % base) - 10 + 65;
		n /= base;
		i++;
	}
	if (neg && base == 10)
		ret[i] = '-';
	ret[++i] = '\0';
	return (ft_strrev(ret));
}

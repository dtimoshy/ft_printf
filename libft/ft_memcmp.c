/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimoshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 15:37:58 by dtimoshy          #+#    #+#             */
/*   Updated: 2018/01/15 11:32:50 by dtimoshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	*str1;

	i = 0;
	str = (unsigned char*)(s1);
	str1 = (unsigned char*)(s2);
	while (i < n)
	{
		if (str[i] != str1[i])
			return (int)(str[i] - str1[i]);
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimoshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 15:24:30 by dtimoshy          #+#    #+#             */
/*   Updated: 2018/01/15 11:31:19 by dtimoshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	a;
	unsigned char	*str;

	i = 0;
	a = (unsigned char)(c);
	str = (unsigned char*)(s);
	while (i < n)
	{
		if (str[i] == a)
			return (str + i);
		i++;
	}
	return (NULL);
}

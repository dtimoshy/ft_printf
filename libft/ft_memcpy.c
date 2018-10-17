/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimoshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 14:17:56 by dtimoshy          #+#    #+#             */
/*   Updated: 2018/01/15 11:30:36 by dtimoshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	i = 0;
	s1 = (unsigned char*)(dst);
	s2 = (unsigned char*)(src);
	if (s1 == s2 || n == 0)
		return (dst);
	while (i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	return (dst);
}

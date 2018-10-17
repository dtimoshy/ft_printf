/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimoshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 15:10:52 by dtimoshy          #+#    #+#             */
/*   Updated: 2018/01/15 11:33:58 by dtimoshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	i = 0;
	s1 = (unsigned char*)(dst);
	s2 = (unsigned char*)(src);
	if (src < dst)
	{
		while (len--)
		{
			s1[len] = s2[len];
		}
	}
	else
		while (i < len)
		{
			s1[i] = s2[i];
			i++;
		}
	return (dst);
}

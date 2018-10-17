/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimoshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 14:29:26 by dtimoshy          #+#    #+#             */
/*   Updated: 2018/01/15 11:31:00 by dtimoshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;
	unsigned char	a;

	i = 0;
	a = (unsigned char)(c);
	s1 = (unsigned char*)(dst);
	s2 = (unsigned char*)(src);
	while (i < n)
	{
		if (s2[i] == a)
		{
			s1[i] = s2[i];
			return (s1 + (i + 1));
		}
		s1[i] = s2[i];
		i++;
	}
	return (NULL);
}

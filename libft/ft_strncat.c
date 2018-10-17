/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimoshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 13:40:43 by dtimoshy          #+#    #+#             */
/*   Updated: 2018/01/04 13:52:00 by dtimoshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char *s1;
	char *s2;

	s1 = dest;
	s2 = (char *)src;
	while (*s1)
		s1++;
	while (n-- && *s2)
		*s1++ = *s2++;
	*s1 = '\0';
	return (dest);
}

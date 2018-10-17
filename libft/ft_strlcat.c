/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimoshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 14:00:40 by dtimoshy          #+#    #+#             */
/*   Updated: 2018/01/04 15:56:20 by dtimoshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t k;

	i = 0;
	k = 0;
	j = ft_strlen(src);
	if (ft_strlen(dst) >= size)
		return (size + j);
	while (i < size - 1 && dst[i] != '\0')
		i++;
	j += i;
	while (i < size - 1 && src[k] != '\0')
	{
		dst[i] = src[k];
		i++;
		k++;
	}
	dst[i] = '\0';
	return (j);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimoshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 11:50:54 by dtimoshy          #+#    #+#             */
/*   Updated: 2018/01/15 11:30:10 by dtimoshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

void	*ft_memalloc(size_t size)
{
	void			*str;
	unsigned char	*s;
	size_t			i;

	i = 0;
	str = (void*)malloc(sizeof(void) * size);
	s = (unsigned char*)(str);
	if (str == NULL)
		return (NULL);
	while (i < size)
	{
		s[i] = 0;
		i++;
	}
	return (str);
}

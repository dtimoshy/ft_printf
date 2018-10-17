/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimoshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 15:59:02 by dtimoshy          #+#    #+#             */
/*   Updated: 2018/01/15 12:42:23 by dtimoshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	int			j;
	int			i;
	char		*str;

	i = 0;
	j = start;
	if ((int)len < 0 || (int)start < 0 || s == NULL)
		return (NULL);
	if (j + len > ft_strlen(s))
		len = 0;
	str = (char*)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	while (i < (int)len)
	{
		str[i] = s[j];
		j++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

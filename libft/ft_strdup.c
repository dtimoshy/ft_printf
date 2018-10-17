/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimoshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 11:43:42 by dtimoshy          #+#    #+#             */
/*   Updated: 2018/01/04 15:31:26 by dtimoshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*buff;

	i = 0;
	buff = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (buff == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		buff[i] = s[i];
		i++;
	}
	buff[i] = '\0';
	return (buff);
}

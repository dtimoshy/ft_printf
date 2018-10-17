/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimoshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 13:02:24 by dtimoshy          #+#    #+#             */
/*   Updated: 2018/01/05 13:44:28 by dtimoshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	if (s == NULL)
		return (NULL);
	j = ft_strlen(s);
	str = (char*)malloc(sizeof(char) * (j + 1));
	if (str == NULL)
		return (NULL);
	while (i < j)
	{
		str[i] = f(s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

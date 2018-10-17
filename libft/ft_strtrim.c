/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimoshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 16:38:13 by dtimoshy          #+#    #+#             */
/*   Updated: 2018/01/15 12:42:33 by dtimoshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	int		start;
	int		i;
	int		end;
	char	*str;

	start = 0;
	i = 0;
	if (s == NULL)
		return (NULL);
	end = ft_strlen(s) - 1;
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	if (start <= end)
		while (s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
			end--;
	if (!(str = (char*)malloc(sizeof(char) * ((end - start) + 2))))
		return (NULL);
	while (start <= end)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

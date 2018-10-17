/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countword_delim.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimoshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 12:08:41 by dtimoshy          #+#    #+#             */
/*   Updated: 2018/01/15 12:35:06 by dtimoshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_countword_delim(char const *s, char c)
{
	int	inword;
	int	count;
	int	i;

	i = 0;
	inword = 0;
	count = 0;
	if (s == NULL || c == 0)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] != c && inword == 0)
		{
			inword = 1;
			count++;
		}
		if (s[i] == c && inword == 1)
			inword = 0;
		i++;
	}
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimoshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 08:14:03 by dtimoshy          #+#    #+#             */
/*   Updated: 2018/01/15 12:04:29 by dtimoshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

static int	get_len(int nbr)
{
	int		i;

	i = (nbr <= 0) ? 1 : 0;
	while (nbr != 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	int				sign;
	unsigned int	j;
	int				i;
	char			*str;

	i = get_len(n);
	j = (n < 0) ? -n : n;
	str = (char*)malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (NULL);
	sign = (n < 0) ? -1 : 1;
	str[i] = '\0';
	i--;
	while (i >= 0)
	{
		str[i] = j % 10 + '0';
		j /= 10;
		i--;
	}
	if (sign < 0)
		str[0] = '-';
	return (str);
}

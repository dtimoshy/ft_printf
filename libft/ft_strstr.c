/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimoshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 16:21:47 by dtimoshy          #+#    #+#             */
/*   Updated: 2018/01/15 11:45:09 by dtimoshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *big, const char *little)
{
	int i;
	int j;
	int z;

	i = 0;
	z = 0;
	while (big[i] != '\0')
	{
		j = 0;
		if (big[i] == little[j])
		{
			z = i;
			while (big[i + j] == little[j] && little[j] != '\0')
				j++;
			if (little[j] == '\0')
				return ((char*)(big + z));
		}
		i++;
	}
	if (little[0] == '\0')
		return ((char*)(big));
	else
		return (NULL);
}

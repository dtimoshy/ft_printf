/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimoshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 10:15:33 by dtimoshy          #+#    #+#             */
/*   Updated: 2018/01/15 11:44:35 by dtimoshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t i;
	size_t j;
	size_t z;

	z = 0;
	i = 0;
	while (big[i] != '\0')
	{
		j = 0;
		if (big[i] == little[j])
		{
			z = i;
			while (big[i + j] == little[j]
			&& little[j] != '\0' && (i + j) < len)
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrarr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimoshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 12:08:11 by dtimoshy          #+#    #+#             */
/*   Updated: 2018/01/15 12:46:22 by dtimoshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstrarr(char **str)
{
	int	index;

	index = 0;
	if (str == NULL)
		return ;
	while (str[index] != NULL && str != NULL)
	{
		ft_putstr(str[index]);
		index++;
	}
}

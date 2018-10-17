/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdelarr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimoshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 12:09:09 by dtimoshy          #+#    #+#             */
/*   Updated: 2018/01/15 12:40:59 by dtimoshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void	ft_strdelarr(char **strarr)
{
	int	i;

	i = 0;
	if (strarr == NULL)
		return ;
	while (strarr[i] != NULL)
		free(strarr[i]);
	free(strarr);
	strarr = NULL;
}

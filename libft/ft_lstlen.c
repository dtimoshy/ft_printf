/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimoshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 12:12:04 by dtimoshy          #+#    #+#             */
/*   Updated: 2018/01/15 12:37:40 by dtimoshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstlen(t_list **alst)
{
	t_list	*temp_list;
	int		i;

	if (alst == NULL)
		return (0);
	temp_list = *alst;
	i = 1;
	while (temp_list->next != NULL)
	{
		temp_list = temp_list->next;
		i++;
	}
	return (i);
}

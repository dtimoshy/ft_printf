/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimoshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 12:08:28 by dtimoshy          #+#    #+#             */
/*   Updated: 2018/01/15 12:35:23 by dtimoshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddend(t_list **alst, t_list *new_list)
{
	t_list	*temp_list;

	temp_list = *alst;
	if (temp_list != NULL)
	{
		while (temp_list->next != NULL)
			temp_list = temp_list->next;
		temp_list->next = new_list;
		new_list->next = NULL;
	}
	else
	{
		*alst = new_list;
		(*alst)->next = NULL;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimoshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 12:12:16 by dtimoshy          #+#    #+#             */
/*   Updated: 2018/01/15 12:45:21 by dtimoshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstreplace(t_list **alst, t_list *old_list, t_list *new_list)
{
	t_list	*temp_list;

	if (alst == NULL || old_list == NULL || new_list == NULL)
		return ;
	temp_list = *alst;
	if (temp_list != old_list)
	{
		while (temp_list->next != NULL && temp_list->next != old_list)
			temp_list = temp_list->next;
		temp_list->next = new_list;
	}
	new_list->next = old_list->next;
	old_list->next = NULL;
}

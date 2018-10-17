/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimoshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 12:11:32 by dtimoshy          #+#    #+#             */
/*   Updated: 2018/01/15 12:26:41 by dtimoshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstinsert(t_list **alst, t_list *new_list)
{
	if (alst == NULL || new_list == NULL)
		return ;
	new_list->next = (*alst)->next;
	(*alst)->next = new_list;
}

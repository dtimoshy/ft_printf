/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimoshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 12:07:36 by dtimoshy          #+#    #+#             */
/*   Updated: 2018/01/15 12:45:56 by dtimoshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*start_newlist;
	t_list	*temp_newlist;

	if (lst == NULL || f == NULL)
		return (NULL);
	if (!(temp_newlist = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!(temp_newlist = f(lst)))
		return (NULL);
	start_newlist = temp_newlist;
	while (lst->next != NULL)
	{
		lst = lst->next;
		if (!(temp_newlist->next = (t_list*)malloc(sizeof(t_list))))
			return (NULL);
		temp_newlist->next = f(lst);
		if (temp_newlist->next == NULL)
			return (NULL);
		temp_newlist = temp_newlist->next;
	}
	return (start_newlist);
}

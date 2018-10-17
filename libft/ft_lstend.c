/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstend.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimoshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 12:11:52 by dtimoshy          #+#    #+#             */
/*   Updated: 2018/01/15 12:36:52 by dtimoshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstend(t_list **alst)
{
	t_list	*temp_list;

	if (alst == NULL)
		return (NULL);
	temp_list = *alst;
	while (temp_list->next != NULL)
		temp_list = temp_list->next;
	return (temp_list);
}

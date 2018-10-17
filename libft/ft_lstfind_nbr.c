/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind_nbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimoshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 12:09:42 by dtimoshy          #+#    #+#             */
/*   Updated: 2018/01/15 12:36:39 by dtimoshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfind_nbr(t_list **alst, size_t num)
{
	size_t	i;
	t_list	*temp_list;

	i = 1;
	if (alst == NULL || num <= 0)
		return (NULL);
	temp_list = *alst;
	while (temp_list->next != NULL && i < num)
	{
		temp_list = temp_list->next;
		i++;
	}
	if (i == num && temp_list != NULL)
		return (temp_list);
	else
		return (NULL);
}

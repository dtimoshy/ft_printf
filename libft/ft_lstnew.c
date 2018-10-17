/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimoshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 12:06:08 by dtimoshy          #+#    #+#             */
/*   Updated: 2018/01/15 12:39:02 by dtimoshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *n_list;

	n_list = NULL;
	if (!(n_list = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		n_list->content = NULL;
		n_list->content_size = 0;
	}
	else
	{
		if (!(n_list->content = malloc(content_size + 1)))
		{
			free(n_list);
			return (NULL);
		}
		n_list->content = ft_memcpy(n_list->content, content, content_size + 1);
		n_list->content_size = content_size;
	}
	n_list->next = NULL;
	return (n_list);
}

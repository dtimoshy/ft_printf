/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_nbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimoshy <dtimoshy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 10:33:07 by dtimoshy          #+#    #+#             */
/*   Updated: 2018/10/02 10:33:10 by dtimoshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap_nbr(void *n1, void *n2, size_t size)
{
	unsigned char	tmp[size];

	ft_memcpy(&(tmp), &(n1), size);
	ft_memcpy(&(*n1), &(*n2), size);
	ft_memcpy(&(*n2), &(*tmp), size);
}

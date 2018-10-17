/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimoshy <dtimoshy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 15:35:06 by dtimoshy          #+#    #+#             */
/*   Updated: 2018/10/17 15:35:09 by dtimoshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char *str)
{
	int		i;
	char	temp;
	int		length;

	length = 0;
	while (str[length])
		length++;
	i = 0;
	while (i < (length / 2))
	{
		temp = str[i];
		str[i] = str[length - i - 1];
		str[length - i - 1] = temp;
		i++;
	}
	return (str);
}

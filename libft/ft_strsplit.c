/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimoshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 11:47:44 by dtimoshy          #+#    #+#             */
/*   Updated: 2018/01/15 12:41:38 by dtimoshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_words(char const *s, char c)
{
	int count_len;
	int i;

	i = 0;
	count_len = 0;
	if (s == NULL || c == 0)
		return (0);
	while (s[i] != '\0' && s[i] != c)
	{
		count_len++;
		i++;
	}
	return (count_len);
}

char		**ft_strsplit(char const *s, char c)
{
	char		**new_str;
	int			index;
	int			num_of_words;
	int			count_len;

	index = 0;
	count_len = 0;
	num_of_words = ft_countword_delim(s, c);
	if (s == NULL || c == 0)
		return (NULL);
	if (!(new_str = (char**)malloc(sizeof(char*) * num_of_words + 1)))
		return (NULL);
	while (index < num_of_words)
	{
		count_len = 0;
		while (s && *s && *s == c)
			s++;
		count_len = len_words((char*)s, c);
		new_str[index] = ft_strsub(s, 0, count_len);
		while (s && *s && *s != c)
			s++;
		index++;
	}
	new_str[index] = NULL;
	return (new_str);
}

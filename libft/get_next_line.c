/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimoshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 10:18:35 by dtimoshy          #+#    #+#             */
/*   Updated: 2018/03/15 10:18:42 by dtimoshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"
#include <stdio.h>

void	ft_lstdelnod(t_list **alst)
{
	t_list *tmp;

	if ((*alst) == NULL)
		return ;
	if ((*alst)->next)
	{
		tmp = *alst;
		*alst = (*alst)->next;
		free(tmp->content);
		free(tmp);
	}
	else
	{
		if ((*alst)->content)
			free((*alst)->content);
		free(*alst);
		*alst = NULL;
	}
}

t_gnl	*get_node(t_gnl **list, unsigned int fd)
{
	t_gnl *prev;
	t_gnl *tmp;

	tmp = *list;
	prev = NULL;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		prev = tmp;
		tmp = tmp->next;
	}
	if (!(tmp = (t_gnl *)malloc(sizeof(t_gnl))))
		return (NULL);
	tmp->fd = fd;
	tmp->no_read = 0;
	tmp->flag = 0;
	tmp->buf = ft_lstnew(NULL, 0);
	tmp->next = NULL;
	if (prev)
		prev->next = tmp;
	if (!(*list))
		*list = tmp;
	return (tmp);
}

int		g_ln(char **ln, size_t *r_off, t_list **beg, void *end)
{
	size_t	length;
	t_list	*tmp;
	size_t	l_off;

	length = 0;
	l_off = *r_off;
	l_off > (*beg)->content_size ? l_off = 0 : l_off;
	if (!end || !(tmp = *beg))
		return (0);
	while (tmp && ((size_t)(end - tmp->content) > tmp->content_size))
	{
		length += (tmp->content_size);
		tmp = tmp->next;
	}
	tmp ? *r_off = (size_t)(end - tmp->content) : 0;
	tmp ? *ln = ft_strnew(length + *r_off - l_off) \
	: ft_strnew(length + BUFF_SIZE - l_off);
	while ((*beg) && (size_t)(end - (*beg)->content) > (*beg)->content_size)
	{
		ft_strncat(*ln, (*beg)->content + l_off, (*beg)->content_size - l_off);
		l_off = 0;
		ft_lstdelnod(beg);
	}
	*beg ? ft_strncat(*ln, (*beg)->content + l_off, (*r_off)++ - l_off) : *ln;
	return (1);
}

int		read_buf(t_gnl *s, char **line, char **buffer, long long *red)
{
	t_list	*current;
	t_list	*new;

	current = s->buf;
	while ((*red = read(s->fd, *buffer, BUFF_SIZE)) > 0)
	{
		new = ft_lstnew((void *)*buffer, (size_t)*red);
		ft_lstaddend(&current, new);
		if (g_ln(line, &(s->flag), &(s->buf), \
			ft_memchr(new->content, '\n', new->content_size)))
			return (1);
		current = new;
	}
	if (*red == 0)
	{
		if (!(*red = current == s->buf && s->flag >= current->content_size))
			g_ln(line, &(s->flag), &(s->buf), current->content +
			current->content_size);
		s->no_read = 1;
		ft_lstdelnod(&(s->buf));
		return (*red) ? 0 : 1;
	}
	return (-1);
}

int		get_next_line(const int fd, char **line)
{
	static t_gnl	*fd_st;
	t_gnl			*current;
	long long		red;
	char			*buffer;

	if (!(line) || fd < 0 || read(fd, &red, 0) < 0)
		return (-1);
	if (!(current = get_node(&fd_st, (unsigned int)fd)))
		return (-1);
	if (current->no_read)
		return (0);
	if (g_ln(line, &(current->flag), &(current->buf),
		ft_memchr(current->buf->content + current->flag, '\n',
		current->buf->content_size - current->flag)))
		return (1);
	if (!(buffer = ft_strnew(BUFF_SIZE)))
		return (-1);
	red = read_buf(current, line, &buffer, &red);
	if (buffer)
		free(buffer);
	return ((int)red);
}

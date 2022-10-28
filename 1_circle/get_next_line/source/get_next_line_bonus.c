/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:06:44 by gyoon             #+#    #+#             */
/*   Updated: 2022/10/28 16:03:55 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	read_buffer(int fd, t_buffer *b)
{
	b->len = read(fd, b->buf, BUFFER_SIZE);
	if (b->len > 0)
		return (1);
	else
		return (0);
}

static t_string	init_string(void)
{
	t_string	s;

	s.str = 0;
	s.len = 0;
	s.size = 0;
	return (s);
}

t_buffer	*get_buffer(int fd, t_buffer *b)
{
	while (1)
	{
		if (b->fd == fd)
			return (b);
		if (!b->next)
		{
			b->next = (t_buffer *) malloc(sizeof(t_buffer));
			if (!b->next)
				return (0);
			b = b->next;
			b->fd = fd;
			b->idx = 0;
			b->len = 0;
			b->next = 0;
			continue ;
		}
		else
			b = b->next;
	}
}

void	delete_buffer(int fd, t_buffer *head)
{
	t_buffer	*curr;
	t_buffer	*temp;

	curr = head;
	temp = 0;
	while (1)
	{
		if (curr->next == 0)
			break ;
		if (curr->next->fd == fd)
		{
			temp = curr->next->next;
			free(curr->next);
			curr->next = temp;
			break ;
		}
		else
			curr = curr->next;
	}
}

char	*get_next_line(int fd)
{
	static t_buffer	head;
	t_buffer		*curr;
	t_string		l;

	curr = get_buffer(fd, &head);
	if (!curr)
		return (0);
	l = init_string();
	while (1)
	{
		if (!curr->idx && !read_buffer(fd, curr))
			break ;
		if (!update_line(&l, *curr))
		{
			delete_buffer(fd, &head);
			return (0);
		}
		update_buffer(curr);
		if (l.str[l.len - 1] == '\n' || curr->idx)
			break ;
	}
	l.str = optimize_string(&l);
	if ((curr->len < BUFFER_SIZE && !curr->idx) || !l.str)
		delete_buffer(fd, &head);
	return (l.str);
}

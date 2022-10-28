/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:06:44 by gyoon             #+#    #+#             */
/*   Updated: 2022/10/28 14:50:20 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	read_buffer(int fd, t_buffer *b)
{
	b->len = read(fd, b->buf, BUFFER_SIZE);
	if (b->len > 0)
		return (1);
	else
		return (0);
}

static void	update_buffer(t_buffer *b)
{
	b->idx = get_index(b->buf, '\n', b->idx, b->len) + 1;
	b->idx %= b->len;
}

static t_string	init_string(void)
{
	t_string	s;

	s.str = 0;
	s.len = 0;
	s.size = 0;
	return (s);
}

char	*get_next_line(int fd)
{
	static t_buffer	b;
	t_string		l;

	l = init_string();
	while (1)
	{
		if (!b.idx && !read_buffer(fd, &b))
			break ;
		if (!update_line(&l, b))
			break ;
		update_buffer(&b);
		if (l.str[l.len - 1] == '\n' || b.idx)
			break ;
	}
	return (optimize_string(&l));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:06:44 by gyoon             #+#    #+#             */
/*   Updated: 2022/10/26 23:34:53 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	read_buffer(int fd, t_buffer *b)
{
	b->len = read(fd, b->buf, BUFFER_SIZE);
	if (b->len > 0)
		return (1);
	else
		return (0);
}

t_string	init_string(void)
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
	if (b.idx)
	{
		if (!update_line(&l, b))
			return (0);
		update_buffer(&b);
	}
	while (!b.idx)
	{
		if (!read_buffer(fd, &b))
			break ;
		if (!update_line(&l, b))
		{
			free(l.str);
			l.str = 0;
			break ;
		}
		update_buffer(&b);
		if (l.str[l.len - 1] == '\n')
			break ;
	}
	return (optimize_string(&l));
}

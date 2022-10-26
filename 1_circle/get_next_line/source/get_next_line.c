/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:06:44 by gyoon             #+#    #+#             */
/*   Updated: 2022/10/26 23:08:59 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static t_buffer	buf;
	t_string		line;

	line = init_string();
	if (buf.idx)
	{
		if (!update_line(&line, buf))
			return (0);
		update_buffer(&buf);
	}
	while (!buf.idx)
	{
		if (!read_buffer(fd, &buf))
			break ;
		if (!update_line(&line, buf))
		{
			if (line.str)
				free(line.str);
			return (0);
		}
		update_buffer(&buf);
		if (line.str[line.len - 1] == '\n')
			break ;
	}
	return (optimize_string(&line));
}

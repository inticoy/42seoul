/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:06:44 by gyoon             #+#    #+#             */
/*   Updated: 2022/10/26 14:12:10 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	read_buffer(int fd, t_buffer *buf)
{
	buf->len = read(fd, buf->buf, BUFFER_SIZE);
	if (buf->len > 0)
		return (1);
	else
		return (0);
}

void	init_string(t_string *str)
{
	str->str = 0;
	str->len = 0;
	str->len_alloc = 0;
}

char	*get_next_line(int fd)
{
	static t_buffer	buf;
	t_string		line;

	init_string(&line);
	if (buf.idx)
	{
		if (!update_line(&line, &buf))
			return (0);
		update_buffer(&buf);
	}
	while (!buf.idx)
	{
		if (!read_buffer(fd, &buf))
			break ;
		if (!update_line(&line, &buf))
		{
			free(line.str);
			line.str = 0;
			break ;
		}
		update_buffer(&buf);
		if (line.str[line.len - 1] == '\n')
			break ;
	}
	return (optimize_string(&line));
}

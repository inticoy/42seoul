/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:06:44 by gyoon             #+#    #+#             */
/*   Updated: 2022/10/15 20:37:57 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*str_from_buf(t_buffer buf);
void	update_idx(t_buffer buf);

char	*get_next_line(int fd)
{
	static t_buffer	buf;
	t_string		line;

	if (buf.index) // if sth's left
	{
		line.string = get_from_buf(buf);
		line.length = 0;
		update_idx(buf);
	}
	while (!buf.index)
	{
		buf.length = read(fd, buf.buffer, BUFFER_SIZE);
	}
	
	return (line.string);
}

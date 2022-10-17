/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:06:44 by gyoon             #+#    #+#             */
/*   Updated: 2022/10/17 20:16:58 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_buffer	buf;
	t_string		line;

	line.string = 0;
	line.length = 0;
	if (buf.index)
	{
		update_line(&line, &buf);
		update_index(&buf);
	}
	while (!buf.index)
	{
		buf.length = read(fd, buf.buffer, BUFFER_SIZE);
		if (buf.length <= 0)
			break ;
		update_line(&line, &buf);
		update_index(&buf);
		if (line.string[line.length - 1] == '\n')
			break ;
	}
	return (line.string);
}

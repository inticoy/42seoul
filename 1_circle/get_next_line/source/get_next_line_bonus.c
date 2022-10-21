/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:06:44 by gyoon             #+#    #+#             */
/*   Updated: 2022/10/19 16:56:07 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_buffer	*add_buffer());

t_buffer	*get_buffer(t_buffer head, int fd)
{
	while (head.next != 0)
	{

	}
	head.next = ;
}

char	*get_next_line(int fd)
{
	static t_buffer	*head;
	t_buffer		*current;
	t_string		line;

	line.str = 0;
	line.len = 0;
	
	
	
	current = get_buffer(head, fd);
	if (buf.idx)
	{
		if (!update_line(&line, &buf))
			return (line.str);
		update_buffer(&buf);
	}
	while (!buf.idx)
	{
		if (read_buffer(fd, &buf) <= 0)
			break ;
		if (!update_line(&line, &buf))
		{
			free(line.str);
			return (0);
		}
		update_buffer(&buf);
		if (line.str[line.len - 1] == '\n')
			break ;
	}
	return (line.str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_timeout.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:06:54 by gyoon             #+#    #+#             */
/*   Updated: 2022/10/21 14:51:40 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_buffer
{
	char	buf[BUFFER_SIZE];
	int		idx;
	int		len;
}	t_buffer;

typedef struct s_string
{
	char	*str;
	int		len;
	int		alloc;
}	t_string;

int		read_buffer(int fd, t_buffer *buf);
int		update_line(t_string *line, t_buffer *buf);
void	update_buffer(t_buffer *buf);
char	*get_next_line(int fd);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:06:54 by gyoon             #+#    #+#             */
/*   Updated: 2022/10/26 23:14:36 by gyoon            ###   ########.fr       */
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
	int		size;
}	t_string;

int			update_line(t_string *l, t_buffer b);
void		update_buffer(t_buffer *b);
char		*optimize_string(t_string *s);
int			read_buffer(int fd, t_buffer *b);
t_string	init_string(void);
char		*get_next_line(int fd);

#endif
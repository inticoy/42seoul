/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:06:54 by gyoon             #+#    #+#             */
/*   Updated: 2022/10/17 18:06:15 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// just for test, erase when commit.
# define BUFFER_SIZE 42

// original
# include <unistd.h>
# include <stdlib.h>

typedef struct s_buffer
{
	char	buffer[BUFFER_SIZE];
	int		index;
	int		length;
}	t_buffer;

typedef struct s_string
{
	char	*string;
	int		length;
}	t_string;

char	*get_next_line(int fd);
int		get_index_nl(char *str, int start, int len);
void	update_line(t_string *line, t_buffer *buf);
void	update_index(t_buffer *buf);

#endif
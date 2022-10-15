/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:06:44 by gyoon             #+#    #+#             */
/*   Updated: 2022/10/15 23:36:37 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// if newline exist, return index of newline
// if not exist, return len.
int	get_index_nl(char *str, int start, int len)
{
	int	i;

	i = start;
	while (i < len)
	{
		if (str[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	return (i);
}

// get char pointer from t_buffer
/*             B  B  B  B  B  B  B  B                   len_line
	case 1.   \n idx x  x  x \n  x  x (len_read = 8) -> 5
	case 2.   \n idx x  x  x  x  x \n (len_read = 8) -> 7
	case 3.   \n idx x  x  x  x  x  x (len_read = 8) -> 7
	case 4.   \n idx x  x  1  1  1  1 (len_read = 4) -> 3
*/

void	update_line(t_string *line, t_buffer *buf)
{
	char	*str;
	int		len;
	int		i;

	if (!line->length)
	{
		len = get_index_nl(buf->buffer, buf->index, buf->length) - buf->index;
		str = (char *) malloc(sizeof(char) * (len + 1));
		i = 0;
		while (i < len)
		{
			str[i] = buf->buffer[buf->index + i];
			i++;
		}
		str[i] = 0;
		line->string = str;
		line->length = len;
	}
	else
	{
		
	}
}



// find next index to read on
void	update_index(t_buffer *buf)
{
	buf->index = get_index_nl(buf->buffer, buf->index, buf->length) + 1;
	buf->index %= buf->length;
}

char	*get_next_line(int fd)
{
	static t_buffer	buf;
	t_string		line;

	line.length = 0;
	if (buf.index) // if sth's left
	{
		update_line(&line, &buf);
		update_index(&buf);
	}
	while (!buf.index)
	{
		buf.length = read(fd, buf.buffer, BUFFER_SIZE);
		update_line(&line, &buf);
		update_index(&buf);
	}
	return (line.string);
}

#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	char	*line;
	int		fd;
	
	fd = open("test0.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s\n", line);
	free(line);
	return (0);
}

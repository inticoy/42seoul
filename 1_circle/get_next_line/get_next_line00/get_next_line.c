/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:06:44 by gyoon             #+#    #+#             */
/*   Updated: 2022/10/15 21:22:32 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// get char pointer from t_buffer
/*             B  B  B  B  B  B  B  B                   len_line
	case 1.   \n idx x  x  x \n  x  x (len_read = 8) -> 5
	case 2.   \n idx x  x  x  x  x \n (len_read = 8) -> 7
	case 3.   \n idx x  x  x  x  x  x (len_read = 8) -> 7
	case 4.   \n idx x  x  1  1  1  1 (len_read = 4) -> 3
*/

char	*str_from_buffer(t_buffer buf)
{
	char	*str;
	int		len;
	int		i;

	i = buf.index;
	while (i < buf.length)
	{
		if (buf.buffer[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	len = i - buf.index;
	str = (char *) malloc(sizeof(char) * (len + 1));
	i = 0;
	while (i < len)
	{
		str[i] = buf.buffer[buf.index + i];
		i++;
	}
	str[i] = 0;
	return (str);
}

void	update_line(t_string *line, t_buffer buf)
{
	char	*str;
	int		len;
	int		i;

	if (!line->length)
	{
		i = buf.index;
		while (i < buf.length)
		{
			if (buf.buffer[i] == '\n')
			{
				i++;
				break ;
			}
			i++;
		}
		len = i - buf.index;
		str = (char *) malloc(sizeof(char) * (len + 1));
		i = 0;
		while (i < len)
		{
			str[i] = buf.buffer[buf.index + i];
			i++;
		}
		str[i] = 0;
		return (str);
	}
	else
	{
		
	}
}

// find next \n or make zero
void	update_idx(t_buffer *buf)
{

}

char	*get_next_line(int fd)
{
	static t_buffer	buf;
	t_string		line;

	line.length = 0;
	if (buf.index) // if sth's left
	{
		update_line(&line, buf);
		update_idx(&buf);
	}
	while (!buf.index)
	{
		buf.length = read(fd, buf.buffer, BUFFER_SIZE);
		line.string = get_from_buffer(buf); // need to update
		line.length = 0;
		update_idx(buf);
	}
	
	return (line.string);
}

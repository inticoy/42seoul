/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:06:49 by gyoon             #+#    #+#             */
/*   Updated: 2022/10/17 18:27:00 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_index_nl(char *str, int start, int len)
{
	int	i;

	i = start;
	while (i < len)
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (len - 1);
}

void	*gnl_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!dst && !src)
		return (0);
	i = 0;
	while (i < n)
	{
		((char *) dst)[i] = ((const char *) src)[i];
		i++;
	}
	return (dst);
}

void	update_line(t_string *line, t_buffer *buf)
{
	char	*str;
	int		len;

	len = get_index_nl(buf->buffer, buf->index, buf->length) - buf->index + 1;
	if (!line->length)
	{
		str = (char *) malloc(sizeof(char) * (len + 1));
		gnl_memcpy(str, buf->buffer + buf->index, len);
	}
	else
	{
		len += line->length;
		str = (char *) malloc(sizeof(char) * (len + 1));
		gnl_memcpy(str, line->string, line->length);
		gnl_memcpy(str + line->length, buf->buffer, len - line->length);
		free(line->string);
	}
	str[len] = 0;
	line->string = str;
	line->length = len;
}

void	update_index(t_buffer *buf)
{
	buf->index = get_index_nl(buf->buffer, buf->index, buf->length) + 1;
	buf->index %= buf->length;
}

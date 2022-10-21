/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:06:49 by gyoon             #+#    #+#             */
/*   Updated: 2022/10/21 18:23:04 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	get_index(char *str, char ch, int begin, int end)
{
	int	i;

	i = begin;
	while (i < end)
	{
		if (str[i] == ch)
			return (i);
		i++;
	}
	return (end - 1);
}

static void	*memcpy(void *dst, const void *src, size_t n)
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

int	read_buffer(int fd, t_buffer *buf)
{
	buf->len = read(fd, buf->buf, BUFFER_SIZE);
	return (buf->len);
}

int	update_line(t_string *line, t_buffer *buf)
{
	char	*str;
	int		len;
	int		len_alloc;

	len = get_index(buf->buf, '\n', buf->idx, buf->len) - buf->idx + 1;
	if (!line->len)
	{
		len_alloc = len * 2 + 1;
		str = (char *) malloc(sizeof(char) * (len_alloc));
		if (!str)
			return (0);
		memcpy(str, buf->buf + buf->idx, len);
		str[len] = 0;
		line->len_alloc = len_alloc;
		line->str = str;
		line->len = len;
		return (1);
	}
	else
	{
		len += line->len;
		if (len + 1 >= line->len_alloc)
		{
			len_alloc = len * 2 + 1;
			str = (char *) malloc(sizeof(char) * (len_alloc));
			if (!str)
				return (0);
			memcpy(str, line->str, line->len);
			memcpy(str + line->len, buf->buf, len - line->len);
			str[len] = 0;
			free(line->str);
			line->str = str;
			line->len = len;
			line->len_alloc = len_alloc;
			return (1);
		}
		else
		{
			memcpy(line->str + line->len, buf->buf, len - line->len);
			line->str[len] = 0;
			line->len = len;
			return (1);
		}
	}
	return (1);
}

void	update_buffer(t_buffer *buf)
{
	buf->idx = get_index(buf->buf, '\n', buf->idx, buf->len) + 1;
	buf->idx %= buf->len;
}

char	*optimize_string(t_string *line)
{
	char	*ret;

	ret = 0;
	if (!line->str)
		return (line->str);
	if (line->len + 1 == line->len_alloc)
		return (line->str);
	else
	{
		ret = (char *) malloc(sizeof(char) * (line->len + 1));
		if (!ret)
			return (0);
		memcpy(ret, line->str, line->len);
		ret[line->len] = 0;
		free(line->str);
		return (ret);
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:06:49 by gyoon             #+#    #+#             */
/*   Updated: 2022/10/26 15:01:45 by gyoon            ###   ########.fr       */
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

int	update_line(t_string *line, t_buffer buf)
{
	char	*str;
	int		len;
	int		len_alloc;

	len = get_index(buf.buf, '\n', buf.idx, buf.len) - buf.idx + 1 + line->len;
	len_alloc = len * 10 + 1;
	if (line->len && len < line->len_alloc)
	{
		memcpy(line->str + line->len, buf.buf, len - line->len);
		line->str[len] = 0;
	}
	else
	{
		str = (char *) malloc(sizeof(char) * (len_alloc));
		if (!str)
			return (0);
		if (!line->len)
			memcpy(str, buf.buf + buf.idx, len);
		else
		{
			memcpy(str, line->str, line->len);
			memcpy(str + line->len, buf.buf, len - line->len);
			free(line->str);
		}
		str[len] = 0;
		line->str = str;
		line->len_alloc = len_alloc;
	}
	line->len = len;
	return (len);
}

void	update_buffer(t_buffer *buf)
{
	buf->idx = get_index(buf->buf, '\n', buf->idx, buf->len) + 1;
	buf->idx %= buf->len;
}

char	*optimize_string(t_string *line)
{
	char	*ret;

	if (!line->str || line->len + 1 == line->len_alloc)
		return (line->str);
	else
	{
		ret = (char *) malloc(sizeof(char) * (line->len + 1));
		if (!ret)
		{
			free(line->str);
			return (0);
		}
		memcpy(ret, line->str, line->len);
		ret[line->len] = 0;
		free(line->str);
		return (ret);
	}
}

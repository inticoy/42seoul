/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:06:49 by gyoon             #+#    #+#             */
/*   Updated: 2022/10/26 15:42:07 by gyoon            ###   ########.fr       */
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
	t_string	temp;

	temp.len = get_index(buf.buf, '\n', buf.idx, buf.len) - buf.idx + 1 + line->len;
	if (line->len && temp.len < line->len_alloc)
		memcpy(line->str + line->len, buf.buf, temp.len - line->len);
	else
	{
		temp.len_alloc = temp.len * 10 + 1;
		temp.str = (char *) malloc(sizeof(char) * (temp.len_alloc));
		if (!temp.str)
		{
			if (line->str)
			{
				free(line->str);
				line->str = 0;
			}
			return (0);
		}
		if (!line->len)
			memcpy(temp.str, buf.buf + buf.idx, temp.len);
		else
		{
			memcpy(temp.str, line->str, line->len);
			memcpy(temp.str + line->len, buf.buf, temp.len - line->len);
			free(line->str);
		}
		line->str = temp.str;
		line->len_alloc = temp.len_alloc;
	}
	line->len = temp.len;
	line->str[line->len] = 0;
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:06:49 by gyoon             #+#    #+#             */
/*   Updated: 2022/10/26 23:09:07 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	get_index(char *s, char c, int begin, int end)
{
	int	i;

	i = begin;
	while (i < end)
	{
		if (s[i] == c)
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

int	update_line(t_string *l, t_buffer b)
{
	t_string	tmp;

	tmp.len = get_index(b.buf, '\n', b.idx, b.len) - b.idx + 1 + l->len;
	if (l->len && tmp.len < l->size)
		memcpy(l->str + l->len, b.buf, tmp.len - l->len);
	else
	{
		l->size = tmp.len * 10 + 1;
		tmp.str = (char *) malloc(sizeof(char) * (l->size));
		if (!tmp.str)
			return (0);
		if (!l->len)
			memcpy(tmp.str, b.buf + b.idx, tmp.len);
		else
		{
			memcpy(tmp.str, l->str, l->len);
			memcpy(tmp.str + l->len, b.buf, tmp.len - l->len);
			free(l->str);
		}
		l->str = tmp.str;
	}
	l->len = tmp.len;
	l->str[l->len] = 0;
	return (1);
}

void	update_buffer(t_buffer *b)
{
	b->idx = get_index(b->buf, '\n', b->idx, b->len) + 1;
	b->idx %= b->len;
}

char	*optimize_string(t_string *s)
{
	char	*ret;

	if (!s->str || s->len + 1 == s->size)
		return (s->str);
	else
	{
		ret = (char *) malloc(sizeof(char) * (s->len + 1));
		if (!ret)
		{
			free(s->str);
			return (0);
		}
		memcpy(ret, s->str, s->len);
		ret[s->len] = 0;
		free(s->str);
		return (ret);
	}
}

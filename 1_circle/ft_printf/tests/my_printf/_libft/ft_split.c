/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:43:46 by gyoon             #+#    #+#             */
/*   Updated: 2022/11/07 21:49:15 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	count_pieces(const char *s, char c)
{
	long	ret;
	int		was_piece;

	ret = 0;
	was_piece = 0;
	while (*s != '\0')
	{
		if (*s == c)
			was_piece = 0;
		else
		{
			if (!was_piece)
				ret++;
			was_piece = 1;
		}
		s++;
	}
	return (ret);
}

static size_t	piecelen(const char *s, char c)
{
	size_t	ret;

	ret = 0;
	while (s[ret] != c && s[ret] != '\0')
		ret++;
	return (ret);
}

static char	*strdup_until_char(const char *s, char c)
{
	const size_t	slen = piecelen(s, c);
	char			*ret;
	size_t			i;

	ret = (char *) malloc(sizeof(char) * (slen + 1));
	if (!ret)
		return (0);
	i = 0;
	while (i < slen)
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

static void	free_split(char **list, size_t i)
{
	while (i > 0)
	{
		free(list[--i]);
		list[i] = 0;
	}
	free(list);
}

char	**ft_split(const char *s, char c)
{
	const long	pieces = count_pieces(s, c);
	char		**ret;
	long		i;

	ret = (char **) malloc(sizeof(char *) * (pieces + 1));
	if (!ret)
		return (0);
	i = 0;
	while (i < pieces)
	{
		while (*s == c)
			s++;
		ret[i] = strdup_until_char(s, c);
		if (!ret[i])
		{
			free_split(ret, i);
			return (0);
		}
		s += piecelen(s, c);
		i++;
	}
	ret[i] = 0;
	return (ret);
}

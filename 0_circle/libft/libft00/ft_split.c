/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:43:46 by gyoon             #+#    #+#             */
/*   Updated: 2022/09/10 20:06:33 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *s, char c)
{
	size_t	ret;
	int		was_word;

	ret = 0;
	was_word = 0;
	while (*s != '\0')
	{
		if (*s == c)
			was_word = 0;
		else
		{
			if (!was_word)
				ret++;
			was_word = 1;
		}
		s++;
	}
	return (ret);
}

static size_t	strlen_until_char(const char *s, char c)
{
	size_t	ret;

	ret = 0;
	while (s[ret] != c && s[ret] != '\0')
		ret++;
	return (ret);
}

static char	*copy_until_char(const char *s, char c)
{
	const size_t	slen = strlen_until_char(s, c);
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

static void	cancel_split(char **list, size_t i)
{
	while (i != 0)
	{
		free(list[i]);
		list[i] = 0;
	}
	free(list);
}

char	**ft_split(const char *s, char c)
{
	const size_t	words = count_words(s, c);
	char			**ret;
	size_t			i;

	ret = (char **) malloc(sizeof(char *) * (words + 1));
	if (!ret)
		return (0);
	i = 0;
	while (i < words)
	{
		while (*s == c)
			s++;
		ret[i] = copy_until_char(s, c);
		if (!ret)
		{
			cancel_split(ret, i);
			ret = 0;
			return (0);
		}
		while (*s != c && *s != '\0')
			s++;
		i++;
	}
	ret[i] = 0;
	return (ret);
}

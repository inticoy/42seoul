/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 21:35:22 by gyoon             #+#    #+#             */
/*   Updated: 2022/09/14 17:25:05 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_exist(char const *s, char ch)
{
	while (*s != '\0')
		if (*s++ == ch)
			return (1);
	return (0);
}

static int	get_start_index(char const *s1, char const *set)
{
	int	ret;

	ret = 0;
	while (s1[ret] != '\0')
	{
		if (!is_exist(set, s1[ret]))
			break ;
		ret++;
	}
	return (ret);
}

static int	get_end_index(char const *s1, char const *set)
{
	const size_t	slen = ft_strlen(s1);
	int				ret;

	ret = slen - 1;
	while (ret >= 0)
	{
		if (!is_exist(set, s1[ret]))
			break ;
		ret--;
	}
	return (ret);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	int		r;
	char	*ret;

	if (!s1 || !set)
		return (0);
	start = get_start_index(s1, set);
	end = get_end_index(s1, set);
	if (start > end)
		i = end + 1;
	else
		i = start;
	ret = (char *) malloc(sizeof(char) * ((end - i + 1) + 1));
	if (!ret)
		return (0);
	r = 0;
	while (i <= end)
		ret[r++] = s1[i++];
	ret[r] = 0;
	return (ret);
}

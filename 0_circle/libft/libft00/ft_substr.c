/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 21:02:40 by gyoon             #+#    #+#             */
/*   Updated: 2022/09/13 15:07:27 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	const size_t	slen = ft_strlen(s);
	size_t			size;
	size_t			i;
	char			*ret;

	if (start >= slen || len == 0)
		size = 0;
	else if (slen >= len + start)
		size = len;
	else
		size = slen - start;
	ret = (char *) malloc(sizeof(char) * (size + 1));
	if (!ret)
		return (0);
	i = 0;
	while (i < len && start + i < slen)
	{
		if (s[start + i] == '\0')
			break ;
		ret[i] = s[start + i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}

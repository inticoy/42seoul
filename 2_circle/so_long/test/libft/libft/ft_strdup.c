/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 19:02:28 by gyoon             #+#    #+#             */
/*   Updated: 2022/09/14 23:35:23 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_strlen(const char *s1)
{
	size_t	len;

	len = 0;
	while (s1[len] != '\0')
		len++;
	return (len);
}

char	*ft_strdup(const char *s1)
{
	const size_t	len = get_strlen(s1);
	char			*ret;
	size_t			i;

	ret = (char *) malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (0);
	i = 0;
	while (i < len)
	{
		ret[i] = s1[i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}

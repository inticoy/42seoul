/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 18:18:51 by gyoon             #+#    #+#             */
/*   Updated: 2022/09/13 16:34:25 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (haystack == 0 && len == 0)
		return (0);
	if (needle[j] == '\0')
		return ((char *) haystack);
	while ((haystack[i] != '\0') && (i < len))
	{
		j = 0;
		while (haystack[i + j] != '\0' && needle[j] != '\0' && i + j < len)
		{
			if (haystack[i + j] != needle[j])
				break ;
			j++;
		}
		if (needle[j] == '\0')
			return ((char *) haystack + i);
		i++;
	}
	if (needle[j] == '\0')
		return ((char *) haystack + i - j);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 14:35:28 by gyoon             #+#    #+#             */
/*   Updated: 2022/09/15 15:31:12 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	len_d;
	unsigned int	len_s;
	size_t			i;

	len_s = ft_strlen(src);
	if (dstsize == 0)
		return (len_s);
	len_d = ft_strlen(dst);
	i = 0;
	if (len_d >= dstsize)
		return (dstsize + len_s);
	while (src[i] != '\0' && len_d + i < dstsize - 1)
	{
		dst[len_d + i] = src[i];
		i++;
	}
	dst[len_d + i] = '\0';
	return (len_d + len_s);
}

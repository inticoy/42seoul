/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 14:04:12 by gyoon             #+#    #+#             */
/*   Updated: 2022/11/09 15:32:13 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (dst < src)
			((char *) dst)[i] = ((const char *) src)[i];
		else if (dst > src)
			((char *) dst)[len - 1 - i] = ((const char *) src)[len - 1 - i];
		i++;
	}
	return (dst);
}

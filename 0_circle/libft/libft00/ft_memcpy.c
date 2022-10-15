/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:56:20 by gyoon             #+#    #+#             */
/*   Updated: 2022/09/10 20:46:19 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dtemp;
	const char	*stemp;
	size_t		i;

	if (!dst && !src)
		return (0);
	dtemp = (char *) dst;
	stemp = (const char *) src;
	i = 0;
	while (i < n)
	{
		dtemp[i] = stemp[i];
		i++;
	}
	return (dst);
}

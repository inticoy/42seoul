/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 14:04:12 by gyoon             #+#    #+#             */
/*   Updated: 2022/09/13 14:31:27 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dtemp;
	const char	*stemp;
	long		i;

	dtemp = (char *) dst;
	stemp = (const char *) src;
	if (dst < src)
	{
		i = 0;
		while (i < (long) len)
		{
			dtemp[i] = stemp[i];
			i++;
		}
	}
	else if (dst > src)
	{
		i = len - 1;
		while (i >= 0)
		{
			dtemp[i] = stemp[i];
			i--;
		}
	}
	return (dst);
}

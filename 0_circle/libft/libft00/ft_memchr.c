/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:05:28 by gyoon             #+#    #+#             */
/*   Updated: 2022/09/10 21:19:21 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ret;
	unsigned char	*stemp;
	size_t			i;

	ret = 0;
	stemp = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (stemp[i] == (unsigned char) c)
		{
			ret = stemp + i;
			return (ret);
		}
		i++;
	}
	return (ret);
}

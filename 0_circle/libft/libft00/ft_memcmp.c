/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 18:09:29 by gyoon             #+#    #+#             */
/*   Updated: 2022/09/07 19:54:13 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*stemp1;
	unsigned char	*stemp2;
	size_t			i;

	stemp1 = (unsigned char *) s1;
	stemp2 = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (stemp1[i] != stemp2[i])
			return (stemp1[i] - stemp2[i]);
		i++;
	}
	return (0);
}

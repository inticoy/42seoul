/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:48:28 by gyoon             #+#    #+#             */
/*   Updated: 2022/09/07 19:54:12 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*btemp;
	size_t			i;

	btemp = (unsigned char *) b;
	i = 0;
	while (i < len)
	{
		btemp[i] = (unsigned char) c;
		i++;
	}
	return (b);
}

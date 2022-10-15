/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:00:02 by gyoon             #+#    #+#             */
/*   Updated: 2022/09/07 19:54:08 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*stemp1;
	const unsigned char	*stemp2;
	size_t				i;

	stemp1 = (const unsigned char *) s1;
	stemp2 = (const unsigned char *) s2;
	i = 0;
	while ((stemp1[i] != '\0' || stemp2[i] != '\0') && (i < n))
	{
		if (stemp1[i] != stemp2[i])
			return (stemp1[i] - stemp2[i]);
		else
			i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 14:50:59 by gyoon             #+#    #+#             */
/*   Updated: 2022/09/10 21:02:22 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ret;
	char	*stemp;
	int		i;

	ret = 0;
	stemp = (char *) s;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			ret = stemp + i;
		i++;
	}
	if (s[i] == (char) c)
		ret = stemp + i;
	return (ret);
}

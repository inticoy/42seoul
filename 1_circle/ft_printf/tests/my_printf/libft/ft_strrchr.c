/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 14:50:59 by gyoon             #+#    #+#             */
/*   Updated: 2022/09/14 17:01:19 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ret;
	int		i;

	ret = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			ret = ((char *) s) + i;
		i++;
	}
	if (s[i] == (char) c)
		ret = ((char *) s) + i;
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 22:55:36 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/17 15:46:19 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static size_t	get_udigits(unsigned int u)
{
	if (u < 10)
		return (1);
	else
		return (get_udigits(u / 10) + 1);
}

static char	*set_utoa(char *s, unsigned int u)
{
	if (u >= 10)
		s = set_utoa(s, u / 10);
	*s++ = '0' + (u % 10);
	return (s);
}

char	*ft_utoa(unsigned int u)
{
	char	*ret;

	ret = (char *)ft_calloc(get_udigits(u) + 1, sizeof(char));
	if (!ret)
		return (FT_NULL);
	set_utoa(ret, u);
	return (ret);
}

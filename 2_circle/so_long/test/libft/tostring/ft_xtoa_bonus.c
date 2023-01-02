/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xtoa_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 22:19:06 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/17 15:46:25 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static size_t	get_xdigits(unsigned int num)
{
	if (num < 16)
		return (1);
	else
		return (get_xdigits(num / 16) + 1);
}

char	*ft_xtoa(unsigned int num)
{
	const size_t		len = get_xdigits(num);
	size_t				i;
	char				*ret;

	ret = (char *) ft_calloc(len + 1, sizeof(char));
	if (!ret)
		return (FT_NULL);
	i = 0;
	while (i < len)
	{
		ret[len - 1 - i] = "0123456789abcdef"[num % 16];
		num /= 16;
		i++;
	}
	return (ret);
}

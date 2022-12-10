/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 22:19:06 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/10 19:16:02 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_xdigits(unsigned int num)
{
	if (num == 0)
		return (0);
	else if (num < 15)
		return (1);
	else
		return (get_xdigits(num / 16) + 1);
}

char	*ft_xtoa(unsigned int num)
{
	const char *const	hex = "0123456789abcdef";
	const size_t		len = get_xdigits(num);
	size_t				i;
	char				*ret;

	ret = (char *) ft_calloc(len + 1, sizeof(char));
	i = 0;
	while (i < len)
	{
		ret[len - 1 - i] = hex[num % 16];
		num /= 16;
		i++;
	}
	return (ret);
}

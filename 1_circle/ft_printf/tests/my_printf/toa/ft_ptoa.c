/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 20:15:14 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/05 22:52:04 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_xdigits(unsigned long long num)
{
	if (num < 15)
		return (1);
	else
		return (get_xdigits(num / 16) + 1);
}

char	*ft_ptoa(void *ptr)
{
	const char *const	hex = "0123456789abcdef";
	unsigned long long	num;
	size_t				len;
	size_t				i;
	char				*ret;

	num = (unsigned long long)ptr;
	len = get_xdigits(num);
	ret = (char *) ft_calloc(len + 3, sizeof(char));
	ret[0] = '0';
	ret[1] = 'x';
	i = 0;
	while (i < len)
	{
		ret[len + 1 - i] = hex[num % 16];
		num /= 16;
		i++;
	}
	return (ret);
}

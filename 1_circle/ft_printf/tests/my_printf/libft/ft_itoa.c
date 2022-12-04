/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:23:02 by gyoon             #+#    #+#             */
/*   Updated: 2022/11/09 15:44:46 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_digits(int n)
{
	if (0 <= n && n < 10)
		return (1);
	else
		return (get_digits(n / 10) + 1);
}

static char	*set_itoa(char *s, int n)
{
	if (-10 < n && n < 0)
		*s++ = '-';
	else if (10 <= n || n <= -10)
		s = set_itoa(s, n / 10);
	*s++ = '0' + ((n > 0) - (n < 0)) * (n % 10);
	return (s);
}

char	*ft_itoa(int n)
{
	char	*ret;

	ret = (char *) ft_calloc(get_digits(n) + 1, sizeof(char));
	if (!ret)
		return (0);
	set_itoa(ret, n);
	return (ret);
}

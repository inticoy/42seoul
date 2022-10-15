/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:23:02 by gyoon             #+#    #+#             */
/*   Updated: 2022/09/10 20:06:58 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_udigits(unsigned int un)
{
	size_t	ret;

	ret = 0;
	if (un < 10)
		return (1);
	else
		ret += get_udigits(un / 10) + 1;
	return (ret);
}

static size_t	get_digits(int n)
{
	size_t	ret;

	ret = 0;
	if (n < 0)
	{
		ret++;
		ret += get_udigits(-n);
	}
	else
		ret += get_udigits(n);
	return (ret);
}

static void	set_uitoa(char *s, unsigned int un)
{
	if (un >= 10)
		set_uitoa(s, un / 10);
	s[get_udigits(un) - 1] = '0' + un % 10;
}

static void	set_itoa(char *s, int n)
{
	size_t			i;

	i = 0;
	if (n < 0)
	{
		s[i++] = '-';
		set_uitoa(s + i, -n);
	}
	else
		set_uitoa(s, n);
	s[get_digits(n)] = '\0';
}

char	*ft_itoa(int n)
{
	const size_t	digits = get_digits(n);
	char			*ret;

	ret = (char *) malloc(sizeof(char) * (digits + 1));
	if (!ret)
		return (0);
	set_itoa(ret, n);
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_precision.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:53:09 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/06 20:23:59 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

#include <stdio.h>

static size_t	get_precisionlen(char *str, t_format *format)
{
	size_t	slen;
	size_t	len;

	slen = ft_strlen(str);
	len = 0;
	if (ft_isintspecfier(format->specifier))
	{
		if (ft_isminus(str[0]))
			len++;
		if (format->precision > slen - len)
			len += format->precision;
		else
			len = slen;
		if (ft_iszero(str[0]) && !format->precision)
			len = 0;
	}
	else if (ft_isstrspecifier(format->specifier))
	{
		if (format->precision < slen)
			len = format->precision;
		else
			len = slen;
	}
	return (len);
}

static void	fill_zero(char *str, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		str[i++] = '0';
}

char	*convert_precision(char *str, t_format *format)
{
	size_t	slen;
	size_t	len;
	size_t	i;
	char	*ret;

	if (!str || !format)
		return (FT_NULL);
	slen = ft_strlen(str);
	len = get_precisionlen(str, format);
	ret = ft_calloc(len + 1, sizeof(char));
	if (!ret)
		return (0);
	if (ft_isintspecfier(format->specifier))
	{
		i = 0;
		if (ft_isminus(str[i]))
			ret[i++] = '-';
		fill_zero(ret + i, len - slen);
		ft_strlcpy(ret + i + len - slen, str, slen - i + 1);
	}
	else if (ft_isstrspecifier(format->specifier))
		ft_strlcpy(ret, str, len + 1);
	free(str);
	return (ret);
}

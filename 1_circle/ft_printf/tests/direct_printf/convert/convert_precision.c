/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_precision.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:53:09 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/17 09:45:47 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>

static size_t	get_precisionlen(t_string tstr, t_format format)
{
	size_t	len;

	len = 0;
	if (ft_isnumfs(format.specifier))
	{
		if (ft_isminus(tstr.str[0]))
			len++;
		if (format.precision > (int)(tstr.len - len))
			len += format.precision;
		else
			len = tstr.len;
		if (ft_iszero(tstr.str[0]) && !format.precision)
			len = 0;
	}
	else if (ft_isstrfs(format.specifier))
	{
		if (format.precision < (int)tstr.len)
			len = format.precision;
		else
			len = tstr.len;
	}
	return (len);
}

static t_string	apply_precision(t_string tstr, t_format format)
{
	const size_t	len = get_precisionlen(tstr, format);
	size_t			i;
	char			*str;

	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
	{
		ft_free_s(tstr.str);
		return (get_tstr(FT_NULL, -1, 0));
	}
	if (!(len == 0))
	{
		if (ft_isnumfs(format.specifier))
		{
			i = 0;
			ft_memset(str, '0', len);
			if (ft_isminus(tstr.str[i]))
				str[i++] = '-';
			ft_memcpy(str + (len - (tstr.len - i)), tstr.str + i, tstr.len - i);
		}
		else if (ft_isstrfs(format.specifier))
			ft_memcpy(str, tstr.str, len);
	}
	ft_free_s(tstr.str);
	return (ft_strtotstr(str));
}

t_string	convert_precision(t_string tstr, t_format format)
{
	if (!tstr.str)
		return (tstr);
	else if (!need_precision(tstr, format))
		return (tstr);
	else
		return (apply_precision(tstr, format));
}

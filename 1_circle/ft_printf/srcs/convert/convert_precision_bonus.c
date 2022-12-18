/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_precision_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:53:09 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/17 15:47:07 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static size_t	get_precisionlen(t_string tstr, t_format format)
{
	size_t	len;

	len = 0;
	if (is_num_format(format))
	{
		if (tstr.str[0] == '-')
			len++;
		if (format.precision > (int)(tstr.len - len))
			len += format.precision;
		else
			len = tstr.len;
		if (tstr.str[0] == '0' && !format.precision)
			len = 0;
	}
	else if (is_str_format(format))
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
		return (get_tstr_auto(FT_NULL));
	}
	if (is_num_format(format) && len)
	{
		i = 0;
		ft_memset(str, '0', len);
		if (tstr.str[i] == '-')
			str[i++] = '-';
		ft_memcpy(str + (len - (tstr.len - i)), tstr.str + i, tstr.len - i);
	}
	else if (is_str_format(format))
		ft_memcpy(str, tstr.str, len);
	ft_free_s(tstr.str);
	return (get_tstr(str, len, len + 1));
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

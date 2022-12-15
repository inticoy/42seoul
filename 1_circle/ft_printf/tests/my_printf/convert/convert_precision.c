/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_precision.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:53:09 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/15 23:30:28 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static size_t	get_precisionlen(t_string *tstr, t_format format)
{
	size_t	len;

	len = 0;
	if (ft_isnumfs(format.specifier))
	{
		if (ft_isminus(tstr->str[0]))
			len++;
		if (format.precision > (int)(tstr->len - len))
			len += format.precision;
		else
			len = tstr->len;
		if (ft_iszero(tstr->str[0]) && !format.precision)
			len = 0;
	}
	else if (ft_isstrfs(format.specifier))
	{
		if (format.precision < (int)tstr->len)
			len = format.precision;
		else
			len = tstr->len;
	}
	return (len);
}

static t_string	*apply_precision(t_string *tstr, t_format format)
{
	const size_t	len = get_precisionlen(tstr, format);
	size_t			i;
	char			*ret;

	i = 0;
	ret = ft_calloc(len + 1, sizeof(char));
	if (!ret)
	{
		del_tstr(tstr);
		return (FT_NULL);
	}
	if (ft_isnumfs(format.specifier))
	{
		if (ft_isminus(tstr->str[i]))
			ret[i++] = '-';
		ft_memset(ret + i, '0', len - i);
		ft_memcpy(ret + i + len - tstr->len, tstr->str + i, tstr->len - i);
	}
	else if (ft_isstrfs(format.specifier))
		ft_memcpy(ret, tstr->str, len);
	del_tstr(tstr);
	return (ft_strtotstr(ret));
}

t_string	*convert_precision(t_string *tstr, t_format format)
{
	if (!tstr)
		return (FT_NULL);
	else if (!need_precision(format))
		return (tstr);
	else
		return (apply_precision(tstr, format));
}

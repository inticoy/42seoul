/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_precision.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:53:09 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/14 16:54:28 by gyoon            ###   ########.fr       */
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

static t_string	*precision(t_string *tstr, t_format format)
{
	size_t			len;
	size_t			i;
	char			*ret;

	len = get_precisionlen(tstr, format);
	i = 0;
	ret = ft_calloc(len + 1, sizeof(char));
	if (!ret)
		return (FT_NULL);
	if (ft_isnumfs(format.specifier))
	{
		if (ft_isminus(tstr->str[i]))
			ret[i++] = '-';
		ft_memset(ret + i, '0', len - tstr->len);
		ft_strlcpy(ret + i + len - tstr->len, tstr->str + i, tstr->len - i + 1);
	}
	else if (ft_isstrfs(format.specifier))
		ft_strlcpy(ret, tstr->str, len + 1);
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
		return (precision(tstr, format));
}

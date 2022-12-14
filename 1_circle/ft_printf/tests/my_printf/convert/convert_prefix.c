/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_prefix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:53:09 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/14 16:08:59 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_bool	isallzero(t_string *tstr)
{
	t_bool	ret;
	int		i;

	ret = ft_true;
	i = 0;
	while (i < tstr->len)
	{
		if (!ft_iszero(tstr->str[i]))
			ret = ft_false;
		i++;
	}
	return (ret);
}

static t_string	*prefix(t_string *tstr, t_format format)
{
	t_string	*ret;

	if (isallzero(tstr))
		return (tstr);
	else if (format.specifier == 'x')
		ret = ft_strtotstr(ft_strjoin("0x", tstr->str));
	else if (format.specifier == 'X')
		ret = ft_strtotstr(ft_strjoin("0X", tstr->str));
	del_tstr(tstr);
	return (ret);
}

t_string	*convert_prefix(t_string *tstr, t_format format)
{
	if (!tstr)
		return (FT_NULL);
	else if (!need_prefix(format))
		return (tstr);
	else
		return (prefix(tstr, format));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_prefix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:53:09 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/17 11:41:30 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_bool	isallzero(t_string tstr)
{
	t_bool	ret;
	int		i;

	ret = ft_true;
	i = 0;
	while (i < tstr.len)
	{
		if (!ft_iszero(tstr.str[i]))
			ret = ft_false;
		i++;
	}
	return (ret);
}

static t_string	apply_prefix(t_string tstr, t_format format)
{
	const char	*prefix = "0x";
	char		*ret;

	if (isallzero(tstr))
		return (tstr);
	ret = ft_strjoin(prefix, tstr.str);
	if (format.specifier == 'X')
		ft_strtoupper(ret);
	ft_free_s(tstr.str);
	return (ft_strtotstr(ret));
}

t_string	convert_prefix(t_string tstr, t_format format)
{
	if (!tstr.str)
		return (tstr);
	else if (!need_prefix(format))
		return (tstr);
	else
		return (apply_prefix(tstr, format));
}

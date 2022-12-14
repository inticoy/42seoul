/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_space.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:53:09 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/14 15:50:49 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_string	*space(t_string *tstr, t_format format)
{
	t_string	*ret;

	if (ft_isplus(tstr->str[0]) || ft_isminus(tstr->str[0]))
		return (tstr);
	else
	{
		ret = ft_strtotstr(ft_strjoin(" ", tstr->str));
		del_tstr(tstr);
		return (ret);
	}
}

t_string	*convert_space(t_string *tstr, t_format format)
{
	if (!tstr)
		return (FT_NULL);
	else if (!need_space(format))
		return (tstr);
	else
		return (space(tstr, format));
}

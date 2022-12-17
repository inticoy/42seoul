/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_space.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:53:09 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/15 22:33:25 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_string	get_tstr_space(void)
{
	t_string	space;

	space.str = " ";
	space.len = 1;
	space.size = 2;
	return (space);
}

static t_string	*apply_space(t_string *tstr, t_format format)
{
	t_string	space;
	t_string	*ret;

	if (ft_isplus(tstr->str[0]) || ft_isminus(tstr->str[0]))
		return (tstr);
	else
	{
		space = get_tstr_space();
		ret = ft_tstrjoin(&space, tstr);
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
		return (apply_space(tstr, format));
}

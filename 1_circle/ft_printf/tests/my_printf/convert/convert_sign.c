/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_sign.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:53:09 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/14 15:45:18 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_string	*sign(t_string *tstr, t_format format)
{
	t_string	*ret;

	if (ft_isminus(tstr->str[0]))
		return (tstr);
	else
	{
		ret = ft_strtotstr(ft_strjoin("+", tstr->str));
		del_tstr(tstr);
		return (ret);
	}
}

t_string	*convert_sign(t_string *tstr, t_format format)
{
	if (!tstr)
		return (FT_NULL);
	else if (!need_sign(format))
		return (tstr);
	else
		return (sign(tstr, format));
}

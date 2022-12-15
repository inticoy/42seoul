/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_sign.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:53:09 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/15 22:38:59 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_string	get_tstr_plus(void)
{
	t_string	plus;

	plus.str = "+";
	plus.len = 1;
	plus.size = 2;
	return (plus);
}

static t_string	*apply_sign(t_string *tstr, t_format format)
{
	t_string	plus;
	t_string	*ret;

	if (ft_isminus(tstr->str[0]))
		return (tstr);
	else
	{
		plus = get_tstr_plus();
		ret = ft_tstrjoin(&plus, tstr);
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
		return (apply_sign(tstr, format));
}

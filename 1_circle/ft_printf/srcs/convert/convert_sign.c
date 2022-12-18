/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_sign.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:53:09 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/17 15:28:44 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_string	apply_sign(t_string tstr)
{
	char		*str;

	if (tstr.str[0] == '-')
		return (tstr);
	else
	{
		str = ft_strjoin("+", tstr.str);
		ft_free_s(tstr.str);
		return (get_tstr_auto(str));
	}
}

t_string	convert_sign(t_string tstr, t_format format)
{
	if (!tstr.str)
		return (tstr);
	else if (!need_sign(format))
		return (tstr);
	else
		return (apply_sign(tstr));
}

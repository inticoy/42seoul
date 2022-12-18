/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_space_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:53:09 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/17 15:47:13 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static t_string	apply_space(t_string tstr)
{
	char		*str;

	str = ft_strjoin(" ", tstr.str);
	ft_free_s(tstr.str);
	return (get_tstr_auto(str));
}

t_string	convert_space(t_string tstr, t_format format)
{
	if (!tstr.str)
		return (tstr);
	else if (!need_space(tstr, format))
		return (tstr);
	else
		return (apply_space(tstr));
}

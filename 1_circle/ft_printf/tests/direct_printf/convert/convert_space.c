/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_space.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:53:09 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/17 11:45:26 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_string	apply_space(t_string tstr, t_format format)
{
	const char	*space = " ";
	char		*sret;

	if (ft_isplus(tstr.str[0]) || ft_isminus(tstr.str[0]))
		return (tstr);
	else
	{
		sret = ft_strjoin(space, tstr.str);
		ft_free_s(tstr.str);
		return (ft_strtotstr(sret));
	}
}

t_string	convert_space(t_string tstr, t_format format)
{
	if (!tstr.str)
		return (tstr);
	else if (!need_space(format))
		return (tstr);
	else
		return (apply_space(tstr, format));
}

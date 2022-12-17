/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_sign.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:53:09 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/17 11:43:53 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_string	apply_sign(t_string tstr, t_format format)
{
	const char	*plus = "+";
	char		*sret;

	if (ft_isminus(tstr.str[0]))
		return (tstr);
	else
	{
		sret = ft_strjoin(plus, tstr.str);
		ft_free_s(tstr.str);
		return (ft_strtotstr(sret));
	}
}

t_string	convert_sign(t_string tstr, t_format format)
{
	if (!tstr.str)
		return (tstr);
	else if (!need_sign(format))
		return (tstr);
	else
		return (apply_sign(tstr, format));
}

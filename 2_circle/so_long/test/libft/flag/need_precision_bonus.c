/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   need_precision_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:42:14 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/17 15:46:54 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

t_bool	need_precision(t_string tstr, t_format format)
{
	if (format.precision < 0)
		return (ft_false);
	else if (format.specifier == 'c')
		return (ft_false);
	else if (format.specifier == 'p')
		return (ft_false);
	else if (format.specifier == '%')
		return (ft_false);
	else if (format.specifier == 's')
	{
		if (format.precision < tstr.len)
			return (ft_true);
		else
			return (ft_false);
	}
	else
		return (ft_true);
}

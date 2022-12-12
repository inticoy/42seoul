/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   need_precision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:42:14 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/12 19:43:59 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_bool	need_precision(t_format format)
{
	if (format.precision < 0)
		return (ft_false);
	else if (format.specifier == 'c')
		return (ft_false);
	else if (format.specifier == 'p')
		return (ft_false);
	else if (format.specifier == '%')
		return (ft_false);
	else
		return (ft_true);
}
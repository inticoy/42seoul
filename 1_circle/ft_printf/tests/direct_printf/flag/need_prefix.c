/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   need_prefix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:41:27 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/14 15:20:18 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_bool	need_prefix(t_format format)
{
	if (!format.flag.prefix)
		return (ft_false);
	else if (format.specifier == 'x')
		return (ft_true);
	else if (format.specifier == 'X')
		return (ft_true);
	else
		return (ft_false);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   need_prefix_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:41:27 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/17 15:46:56 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

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

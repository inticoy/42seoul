/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_num_format_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:03:33 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/17 15:46:45 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

t_bool	is_num_format(t_format format)
{
	const char	c = format.specifier;

	if (c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X')
		return (ft_true);
	else
		return (ft_false);
}

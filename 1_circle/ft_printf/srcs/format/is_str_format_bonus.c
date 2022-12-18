/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_str_format_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:06:46 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/17 15:46:47 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

t_bool	is_str_format(t_format format)
{
	const char	c = format.specifier;

	if (c == 's')
		return (ft_true);
	else
		return (ft_false);
}

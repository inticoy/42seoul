/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_num_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:03:33 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/17 13:05:56 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_bool	is_num_format(t_format format)
{
	const char	c = format.specifier;

	if (c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X')
		return (ft_true);
	else
		return (ft_false);
}

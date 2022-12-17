/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   need_padding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:59:55 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/17 12:47:06 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_bool	need_padding(t_string tstr, t_format format)
{
	if (format.width <= tstr.len)
		return (ft_false);
	else
		return (ft_true);
}

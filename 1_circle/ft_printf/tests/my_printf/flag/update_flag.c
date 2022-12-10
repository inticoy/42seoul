/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 23:29:47 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/10 19:46:40 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag	update_flag(t_flag flag, int c)
{
	if (c == '-')
		flag.left = ft_true;
	else if (c == '+')
		flag.sign = ft_true;
	else if (c == ' ')
		flag.space = ft_true;
	else if (c == '#')
		flag.prefix = ft_true;
	else if (c == '0')
		flag.zero = ft_true;
	return (flag);
}

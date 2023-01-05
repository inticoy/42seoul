/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:26:42 by gyoon             #+#    #+#             */
/*   Updated: 2023/01/05 15:30:19 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ft_printf.h"

t_key	init_key(void)
{
	t_key	k;

	k.press_w = ft_false;
	k.press_a = ft_false;
	k.press_s = ft_false;
	k.press_d = ft_false;
	k.press_shift = ft_false;
	k.press_esc = ft_false;
	return (k);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:30:12 by gyoon             #+#    #+#             */
/*   Updated: 2023/01/09 17:00:13 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_player	init_player(t_map m)
{
	t_player	p;
	int			x;
	int			y;

	y = 0;
	while (y < m.size.y)
	{
		x = 0;
		while (x < m.size.x)
		{
			if (m.map[y][x] == 'P')
				p.pos = init_point(2, x * 32, y * 32, -1);
			x++;
		}
		y++;
	}
	p.is_left = ft_false;
	p.remaining = 96;
	p.v = init_point(2, 0, 0, -1);
	p.a = init_point(2, 0, 0, -1);
	return (p);
}

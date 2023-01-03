/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:21:17 by gyoon             #+#    #+#             */
/*   Updated: 2023/01/03 19:38:18 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"
#include "ft_printf.h"

void	draw_map(t_game	g)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (*g.map.map)
	{
		x = 0;
		while (x < g.map.size.x)
		{
			if ((*g.map.map)[x] == '1')
				mlx_put_image_to_window(g.mlx, g.win, g.assets.blocks[3].img, \
										x * 32, y * 32);
			else if ((*g.map.map)[x] == '0' || (*g.map.map)[x] == 'E' || (*g.map.map)[x] == 'P')
				mlx_put_image_to_window(g.mlx, g.win, g.assets.bg.img, \
										x * 32, y * 32);
			else if ((*g.map.map)[x] == 'C')
				mlx_put_image_to_window(g.mlx, g.win, g.assets.blocks[1].img, \
										x * 32, y * 32);
			if ((*g.map.map)[x] == 'P')
				mlx_put_image_to_window(g.mlx, g.win, g.assets.mario[0].img, \
										x * 32, y * 32);
			x++;
		}
		g.map.map++;
		y++;
	}
}

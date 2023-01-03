/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:21:17 by gyoon             #+#    #+#             */
/*   Updated: 2023/01/03 23:05:02 by gyoon            ###   ########.fr       */
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
	mlx_clear_window(g.mlx, g.win);
	while (*g.map.map)
	{
		x = 0;
		while (x < g.map.size.x)
		{
			if ((*g.map.map)[x] == '1')
				mlx_put_image_to_window(g.mlx, g.win, g.assets.blocks[2].img, \
										x * 32, y * 32);
			else if ((*g.map.map)[x] == '0' || (*g.map.map)[x] == 'E' || (*g.map.map)[x] == 'P')
				mlx_put_image_to_window(g.mlx, g.win, g.assets.bg.img, \
										x * 32, y * 32);
			else if ((*g.map.map)[x] == 'C')
			{
				if ((g.frame / 8) % 5 == 0 || (g.frame / 8) % 5 == 4)
					mlx_put_image_to_window(g.mlx, g.win, g.assets.coin_block[0].img, \
										x * 32, y * 32);
				else if ((g.frame / 8) % 5 == 1 || (g.frame / 8) % 5 == 3)
					mlx_put_image_to_window(g.mlx, g.win, g.assets.coin_block[1].img, \
										x * 32, y * 32);
				else if ((g.frame / 8) % 5 == 2)
					mlx_put_image_to_window(g.mlx, g.win, g.assets.coin_block[2].img, \
										x * 32, y * 32);
			}
			x++;
		}
		g.map.map++;
		y++;
	}
	if (g.player.v.x > 0)
	{
		if ((g.frame / 8) % 3 == 0)
			mlx_put_image_to_window(g.mlx, g.win, g.assets.mario[1].img, \
			g.player.pos.x, g.player.pos.y);
		if ((g.frame / 8) % 3 == 1)
			mlx_put_image_to_window(g.mlx, g.win, g.assets.mario[2].img, \
			g.player.pos.x, g.player.pos.y);
		if ((g.frame / 8) % 3 == 2)
			mlx_put_image_to_window(g.mlx, g.win, g.assets.mario[3].img, \
			g.player.pos.x, g.player.pos.y);
	}
	else
		mlx_put_image_to_window(g.mlx, g.win, g.assets.mario[0].img, \
			g.player.pos.x, g.player.pos.y);
}

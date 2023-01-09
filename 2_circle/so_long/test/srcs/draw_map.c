/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:39:39 by gyoon             #+#    #+#             */
/*   Updated: 2023/01/09 21:02:49 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ft_printf.h"
#include "mlx.h"

void	draw_map(t_game g)
{
	int	x;
	int	y;

	y = 0;
	while (*g.map.map)
	{
		x = 0;
		while (x < g.map.size.x)
		{
			mlx_put_image_to_window(g.mlx, g.win,g.assets.bg.img, x * 32, y * 32);
			if ((*g.map.map)[x] == '1')
				mlx_put_image_to_window(g.mlx, g.win, g.assets.blocks[0].img, x * 32, y * 32);
			else if ((*g.map.map)[x] == 'C')
			{
				if ((g.frame / 8) % 5 == 0 || (g.frame / 8) % 5 == 4)
					mlx_put_image_to_window(g.mlx, g.win, g.assets.coin_block[0].img, x * 32, y * 32);
				else if ((g.frame / 8) % 5 == 1 || (g.frame / 8) % 5 == 3)
					mlx_put_image_to_window(g.mlx, g.win, g.assets.coin_block[1].img, x * 32, y * 32);
				else if ((g.frame / 8) % 5 == 2)
					mlx_put_image_to_window(g.mlx, g.win, g.assets.coin_block[2].img, x * 32, y * 32);
			}
			x++;
		}
		g.map.map++;
		y++;
	}
}

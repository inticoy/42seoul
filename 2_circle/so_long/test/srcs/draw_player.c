/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:46:33 by gyoon             #+#    #+#             */
/*   Updated: 2023/01/05 15:47:13 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

void	draw_player(t_game g)
{
	if (g.player.left)
	{
		if (g.player.v.x < 0)
		{
			if ((g.frame / 8) % 3 == 0)
				mlx_put_image_to_window(g.mlx, g.win, g.assets.mario[7].img, \
				g.player.pos.x, g.player.pos.y);
			if ((g.frame / 8) % 3 == 1)
				mlx_put_image_to_window(g.mlx, g.win, g.assets.mario[8].img, \
				g.player.pos.x, g.player.pos.y);
			if ((g.frame / 8) % 3 == 2)
				mlx_put_image_to_window(g.mlx, g.win, g.assets.mario[9].img, \
				g.player.pos.x, g.player.pos.y);
		}
		else if (g.player.v.x > 0)
			mlx_put_image_to_window(g.mlx, g.win, g.assets.mario[10].img, \
			g.player.pos.x, g.player.pos.y);
		else
			mlx_put_image_to_window(g.mlx, g.win, g.assets.mario[6].img, \
			g.player.pos.x, g.player.pos.y);
	}
	else
	{
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
		else if (g.player.v.x < 0)
			mlx_put_image_to_window(g.mlx, g.win, g.assets.mario[4].img, \
			g.player.pos.x, g.player.pos.y);
		else
			mlx_put_image_to_window(g.mlx, g.win, g.assets.mario[0].img, \
			g.player.pos.x, g.player.pos.y);
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:46:33 by gyoon             #+#    #+#             */
/*   Updated: 2023/01/05 16:00:30 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

void	draw_player(t_game g)
{
	int	i;

	if (g.player.left)
	{
		if (g.player.v.x < 0)
			i = 7 + (g.frame / 8) % 3;
		else if (g.player.v.x > 0)
			i = 10;
		else
			i = 6;
	}
	else
	{
		if (g.player.v.x > 0)
			i = 1 + (g.frame / 8) % 3;
		else if (g.player.v.x < 0)
			i = 4;
		else
			i = 0;
	}
	mlx_put_image_to_window(g.mlx, g.win, g.assets.mario[i].img, g.player.pos.x, g.player.pos.y);
}

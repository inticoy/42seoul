/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:38:06 by gyoon             #+#    #+#             */
/*   Updated: 2023/01/04 13:51:23 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "mlx.h"
#include "so_long.h"

int	main(void)
{
	t_game	g;

	g.frame = 0;
	g.mlx = mlx_init();
	g.map = read_map("./maps/1-1.ber");
	for (int y = 0; y < g.map.size.y; y++)
	{
		for (int x = 0; x < g.map.size.x; x++)
		{
			if (g.map.map[y][x] == 'P')
			{
				g.player.pos.x = x * 32;
				g.player.pos.y = y * 32;
			}
		}
	}
	g.player.left = ft_false;
	g.player.v.x = 0;
	g.player.v.y = 0;
	g.player.a.x = 0;
	g.player.a.y = 0;
	g.assets = read_assets(g.mlx);
	g.size = init_point(2, 32 * g.map.size.x, 32 * g.map.size.y, -1);
	g.win = mlx_new_window(g.mlx, g.size.x, g.size.y, TITLE);
	g.key.press_w = ft_false;
	g.key.press_a = ft_false;
	g.key.press_s = ft_false;
	g.key.press_d = ft_false;

	draw_map(g);
	mlx_hook(g.win, E_KEY_PRESS, M_KEY_PRESS, hook_key_press, &g);
	mlx_hook(g.win, E_KEY_RELEASE, M_KEY_RELEASE, hook_key_release, &g);
	mlx_loop_hook(g.mlx, hook_loop, &g);
	mlx_loop(g.mlx);
	return (0);
}

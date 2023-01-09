/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:26:47 by gyoon             #+#    #+#             */
/*   Updated: 2023/01/09 22:48:24 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

t_game	init_game(void)
{
	t_game	g;

	g.frame = 0;
	g.mlx = mlx_init();
	g.map = read_map("./maps/1-1.ber");
	g.player = init_player(g.map);
	g.assets = read_assets(g.mlx);
	g.size = init_point(2, 32 * g.map.size.x, 32 * g.map.size.y, -1);
	g.win = mlx_new_window(g.mlx, g.size.x, g.size.y, TITLE);
	g.key = init_key();
	return (g);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_assets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 19:54:19 by gyoon             #+#    #+#             */
/*   Updated: 2023/01/03 20:09:35 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_assets	read_assets(void *mlx)
{
	t_assets	assets;

	assets.bg = read_image(mlx, "./assets/sky_0.xpm");
	assets.blocks[0] = read_image(mlx, "./assets/ground_0.xpm");
	assets.blocks[1] = read_image(mlx, "./assets/item_0.xpm");
	assets.blocks[2] = read_image(mlx, "./assets/stair_0.xpm");
	assets.blocks[3] = read_image(mlx, "./assets/wall_0.xpm");
	assets.mario[0] = read_image(mlx, "./assets/mario_0.xpm");
	assets.mario[1] = read_image(mlx, "./assets/mario_1.xpm");
	assets.mario[2] = read_image(mlx, "./assets/mario_2.xpm");
	assets.mario[3] = read_image(mlx, "./assets/mario_3.xpm");
	assets.mario[4] = read_image(mlx, "./assets/mario_4.xpm");
	assets.mario[5] = read_image(mlx, "./assets/mario_5.xpm");
	return (assets);
}

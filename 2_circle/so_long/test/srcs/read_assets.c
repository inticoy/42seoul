/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_assets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 19:54:19 by gyoon             #+#    #+#             */
/*   Updated: 2023/01/10 20:14:22 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_assets	read_assets(void *mlx)
{
	t_assets	assets;

	assets.block[0] = read_image(mlx, "./assets/sky_0.xpm");
	assets.block[1] = read_image(mlx, "./assets/ground_0.xpm");
	assets.block[2] = read_image(mlx, "./assets/stair_0.xpm");
	assets.block[3] = read_image(mlx, "./assets/wall_0.xpm");
	assets.block[10] = read_image(mlx, "./assets/item_0.xpm");
	assets.block[11] = read_image(mlx, "./assets/item_1.xpm");
	assets.block[12] = read_image(mlx, "./assets/item_2.xpm");
	assets.block[13] = read_image(mlx, "./assets/item_3.xpm");
	assets.mario[0] = read_image(mlx, "./assets/mario_0.xpm");
	assets.mario[1] = read_image(mlx, "./assets/mario_1.xpm");
	assets.mario[2] = read_image(mlx, "./assets/mario_2.xpm");
	assets.mario[3] = read_image(mlx, "./assets/mario_3.xpm");
	assets.mario[4] = read_image(mlx, "./assets/mario_4.xpm");
	assets.mario[5] = read_image(mlx, "./assets/mario_5.xpm");
	assets.mario[6] = read_image(mlx, "./assets/mario_6.xpm");
	assets.mario[7] = read_image(mlx, "./assets/mario_7.xpm");
	assets.mario[8] = read_image(mlx, "./assets/mario_8.xpm");
	assets.mario[9] = read_image(mlx, "./assets/mario_9.xpm");
	assets.mario[10] = read_image(mlx, "./assets/mario_10.xpm");
	assets.mario[11] = read_image(mlx, "./assets/mario_11.xpm");
	return (assets);
}

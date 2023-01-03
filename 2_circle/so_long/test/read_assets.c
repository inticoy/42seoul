/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_assets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 19:54:19 by gyoon             #+#    #+#             */
/*   Updated: 2023/01/03 15:35:45 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_assets	read_assets(void *mlx)
{
	t_assets	assets;

	assets.bg = read_image(mlx, "./assets/bg_sky_32.xpm");
	assets.blocks[0] = read_image(mlx, "./assets/block_ground_32.xpm");
	assets.blocks[1] = read_image(mlx, "./assets/block_item_32.xpm");
	assets.blocks[2] = read_image(mlx, "./assets/block_stair_32.xpm");
	assets.blocks[3] = read_image(mlx, "./assets/block_wall_32.xpm");
	assets.mario[0] = read_image(mlx, "./assets/ch_mario_small_0_32.xpm");
	assets.mario[1] = read_image(mlx, "./assets/ch_mario_small_1_32.xpm");
	assets.mario[2] = read_image(mlx, "./assets/ch_mario_small_2_32.xpm");
	assets.mario[3] = read_image(mlx, "./assets/ch_mario_small_3_32.xpm");
	assets.mario[4] = read_image(mlx, "./assets/ch_mario_small_4_32.xpm");
	assets.mario[5] = read_image(mlx, "./assets/ch_mario_small_5_32.xpm");
	return (assets);
}

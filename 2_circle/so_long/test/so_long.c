/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:38:06 by gyoon             #+#    #+#             */
/*   Updated: 2023/01/03 15:46:49 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "mlx.h"
#include "so_long.h"

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

int	key_hook(int keycode, int vars)
{
	int	i;

	i = vars;
	i++;
	ft_printf("key : %d\n", keycode);
	return (0);
}

int	main(void)
{
	t_game	game;
	t_image	mario;

	game.mlx = mlx_init();
	game.map = read_map("./maps/1-1.ber");
	ft_printf("%d %d \n", game.map.size.x, game.map.size.y);
	game.assets = read_assets(game.mlx);
	game.size = init_point(2, 32 * game.map.size.x, 32 * game.map.size.y, -1);
	game.win = mlx_new_window(game.mlx, game.size.x, game.size.y, \
								"Super Mario Bros.");
	draw_map(game);

	mlx_key_hook(game.win, key_hook, 0);
	mlx_loop(game.mlx);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:38:06 by gyoon             #+#    #+#             */
/*   Updated: 2023/01/03 22:52:10 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "mlx.h"
#include "so_long.h"

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

int	key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_A)
		game->key.press_a = ft_true;
	if (keycode == KEY_D)
		game->key.press_d = ft_true;
	if (keycode == KEY_S)
		game->key.press_s = ft_true;
	if (keycode == KEY_W)
		game->key.press_w = ft_true;
	ft_printf("key : %d\n", keycode);
	return (0);
}

int	key_hook2(int keycode, t_game *game)
{
	if (keycode == KEY_A)
		game->key.press_a = ft_false;
	if (keycode == KEY_D)
		game->key.press_d = ft_false;
	if (keycode == KEY_S)
		game->key.press_s = ft_false;
	if (keycode == KEY_W)
		game->key.press_w = ft_false;
	ft_printf("key : %d\n", keycode);
	return (0);
}

int	loop_hook(t_game *game)
{
	game->frame++;
	if (game->frame % 8 == 0)
	{
		if (game->key.press_a)
		{
			if (game->player.v.x > -4)
				game->player.v.x--;
		}
		else
		{
			if (game->player.v.x < 0)
				game->player.v.x++;
		}
		if (game->key.press_d)
		{
			if (game->player.v.x < 4)
				game->player.v.x++;
		}
		else
		{
			if (game->player.v.x > 0)
				game->player.v.x--;
		}
	}
	game->player.pos.x += game->player.v.x;
	if (game->key.press_w)
		game->player.pos.y -= 6;
	if (game->key.press_s)
		game->player.pos.y += 8;
	draw_map(*game);
	return (0);
}

int	main(void)
{
	t_game	game;
	t_image	mario;

	game.frame = 0;
	game.mlx = mlx_init();
	game.map = read_map("./maps/1-1.ber");
	for (int y = 0; y < game.map.size.y; y++)
	{
		for (int x = 0; x < game.map.size.x; x++)
		{
			if (game.map.map[y][x] == 'P')
			{
				game.player.pos.x = x * 32;
				game.player.pos.y = y * 32;
			}
		}
	}
	game.player.v.x = 0;
	game.player.v.y = 0;
	game.assets = read_assets(game.mlx);
	game.size = init_point(2, 32 * game.map.size.x, 32 * game.map.size.y, -1);
	game.win = mlx_new_window(game.mlx, game.size.x, game.size.y, \
								"Super Mario Bros.");
	game.key.press_w = ft_false;
	game.key.press_a = ft_false;
	game.key.press_s = ft_false;
	game.key.press_d = ft_false;

	draw_map(game);
	mlx_hook(game.win, 2, 1L<<0, key_hook, &game);
	mlx_hook(game.win, 3, 1L<<1, key_hook2, &game);
	mlx_loop_hook(game.mlx, loop_hook, &game);
	mlx_loop(game.mlx);
	return (0);
}

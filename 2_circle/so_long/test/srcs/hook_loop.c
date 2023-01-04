/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 13:49:14 by gyoon             #+#    #+#             */
/*   Updated: 2023/01/04 16:39:52 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ft_printf.h"

int	hook_loop(t_game *game)
{
	game->frame++;
	if (game->frame % 2 == 0)
	{
		game->player.a.x = 0;
		if (game->key.press_a)
		{
			game->player.left = ft_true;
			if (game->player.v.x > -4)
				game->player.a.x--;
		}
		else
		{
			if (game->frame % 8 == 0)
				if (game->player.v.x < 0)
					game->player.a.x++;
		}
		if (game->key.press_d)
		{
			game->player.left = ft_false;
			if (game->player.v.x < 4)
				game->player.a.x++;
		}
		else
		{
			if (game->frame % 8 == 0)
				if (game->player.v.x > 0)
					game->player.a.x--;
		}
	}
	ft_printf("here : %d %d %d \n", game->player.a.x, game->player.v.x, game->player.pos.x);
	game->player.v.x += game->player.a.x;
	game->player.pos.x += game->player.v.x;
	if (game->key.press_w)
		game->player.pos.y -= 6;
	if (game->key.press_s)
		game->player.pos.y += 8;
	draw_map(*game);
	return (0);
}

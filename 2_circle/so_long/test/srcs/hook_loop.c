/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 13:49:14 by gyoon             #+#    #+#             */
/*   Updated: 2023/01/05 14:17:00 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ft_printf.h"

int	hook_loop(t_game *game)
{
	game->frame++;
	game->player.a.x = 0;
	if (game->key.press_d)
	{
		game->player.left = ft_false;
		if (0 <= game->player.v.x && game->player.v.x < 4 && game->frame % 8 == 0)
			game->player.a.x = 1;
	}
	else
	{
		if (game->player.v.x > 0 && game->frame % 8 == 0)
			game->player.a.x = -1;
	}
	if (game->key.press_a)
	{
		game->player.left = ft_true;
		if (-4 < game->player.v.x && game->player.v.x <= 0 && game->frame % 8 == 0)
			game->player.a.x = -1;
	}
	else
	{
		if (game->player.v.x < 0 && game->frame % 8 == 0)
			game->player.a.x = 1;
	}
	
	//ft_printf("here : %d %d %d \n", game->player.a.x, game->player.v.x, game->player.pos.x);
	game->player.v.x += game->player.a.x;
	game->player.pos.x += game->player.v.x;
	if (game->key.press_w)
		game->player.pos.y -= 6;
	if (game->key.press_s)
		game->player.pos.y += 8;
	draw_game(*game);
	return (0);
}

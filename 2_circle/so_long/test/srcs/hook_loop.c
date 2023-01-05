/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 13:49:14 by gyoon             #+#    #+#             */
/*   Updated: 2023/01/05 15:51:30 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ft_printf.h"

int	hook_loop(t_game *g)
{
	g->frame++;
	g->player.a.x = 0;
	if (g->key.press_d)
	{
		g->player.left = ft_false;
		if (0 <= g->player.v.x && g->player.v.x < 4 && g->frame % 2 == 0)
			g->player.a.x = 1;
	}
	else
	{
		if (g->player.v.x > 0 && g->frame % 8 == 0)
			g->player.a.x = -1;
	}
	if (g->key.press_a)
	{
		g->player.left = ft_true;
		if (-4 < g->player.v.x && g->player.v.x <= 0 && g->frame % 2 == 0)
			g->player.a.x = -1;
	}
	else
	{
		if (g->player.v.x < 0 && g->frame % 8 == 0)
			g->player.a.x = 1;
	}
	g->player.v.x += g->player.a.x;
	g->player.pos.x += g->player.v.x;
	if (g->key.press_w)
		g->player.pos.y -= 6;
	if (g->key.press_s)
		g->player.pos.y += 8;
	draw_game(*g);
	return (0);
}

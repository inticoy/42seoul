/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 13:49:14 by gyoon             #+#    #+#             */
/*   Updated: 2023/01/05 16:45:20 by gyoon            ###   ########.fr       */
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


	g->player.a.y = 0;
	if (g->key.press_s)
	{
		if (0 <= g->player.v.y && g->player.v.y < 4 && g->frame % 2 == 0)
			g->player.a.y = 1;
	}
	else
	{
		if (g->player.v.y > 0 && g->frame % 8 == 0)
			g->player.a.y = -1;
	}
	if (g->key.press_w)
	{
		if (-4 < g->player.v.y && g->player.v.y <= 0 && g->frame % 2 == 0)
			g->player.a.y = -1;
	}
	else
	{
		if (g->player.v.y < 0 && g->frame % 8 == 0)
			g->player.a.y = 1;
	}
	g->player.v.y += g->player.a.y;
	
	int blocked = 0;
	t_point	next;
	next = init_point(2, g->player.pos.x + g->player.v.x, g->player.pos.y + g->player.v.y, -1);
	if (g->map.map[next.y/32][next.x/32] == '1')
	{
		blocked = 1;
		ft_printf("A\n");
	}
	if (g->map.map[next.y/32][(next.x + 31)/32] == '1')
	{
		blocked = 1;
		ft_printf("B\n");
	}
	if (g->map.map[(next.y + 31)/32][next.x/32] == '1')
	{
		blocked = 1;
		ft_printf("C\n");
	}
	if (g->map.map[(next.y + 31)/32][(next.x + 31)/32] == '1')
	{
		blocked = 1;
		ft_printf("D\n");
	}
	if (!blocked)
	{
		g->player.pos.x += g->player.v.x;
		g->player.pos.y += g->player.v.y;
	}
	draw_game(*g);
	return (0);
}

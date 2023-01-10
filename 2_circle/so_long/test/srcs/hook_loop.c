/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 13:49:14 by gyoon             #+#    #+#             */
/*   Updated: 2023/01/09 19:32:53 by gyoon            ###   ########.fr       */
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
		g->player.is_left = ft_false;
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
		g->player.is_left = ft_true;
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
	if (g->key.press_w)
	{
		if (g->player.remaining > 0 && -12 < g->player.v.y && g->player.v.y <= 0)
			g->player.a.y = -8;
		else if (g->player.remaining > 0 && -12 == g->player.v.y)
			g->player.a.y = -2;
	}
	g->player.a.y += 2;
	if (g->player.v.y + g->player.a.y >= -12 && g->player.v.y + g->player.a.y <= 12)
		g->player.v.y += g->player.a.y;
	ft_printf("%d %d\n", g->player.v.y, g->player.a.y);

	int	blocked_x = 0;
	int	blocked_y = 0;
	t_point	next_x;
	t_point	next_y;

	next_x = init_point(2, g->player.pos.x + g->player.v.x, g->player.pos.y, -1);
	
	if (g->map.map[next_x.y/32][next_x.x/32] == '1')
	{
		blocked_x = 1;
		ft_printf("A\n");
	}
	if (g->map.map[next_x.y/32][(next_x.x + 31)/32] == '1')
	{
		blocked_x = 1;
		ft_printf("B\n");
	}
	if (g->map.map[(next_x.y + 31)/32][next_x.x/32] == '1')
	{
		blocked_x = 1;
		ft_printf("C\n");
	}
	if (g->map.map[(next_x.y + 31)/32][(next_x.x + 31)/32] == '1')
	{
		blocked_x = 1;
		ft_printf("D\n");
	}
	if (blocked_x)
		g->player.v.x = 0;
	else
		g->player.pos.x += g->player.v.x;

	next_y = init_point(2, g->player.pos.x, g->player.pos.y + g->player.v.y, -1);

	if (g->map.map[next_y.y/32][next_y.x/32] == '1')
	{
		blocked_y = 1;
		g->player.remaining = 0;
		ft_printf("A\n");
	}
	if (g->map.map[next_y.y/32][(next_y.x + 31)/32] == '1')
	{
		blocked_y = 1;
		g->player.remaining = 0;
		ft_printf("B\n");
	}
	if (g->map.map[(next_y.y + 31)/32][next_y.x/32] == '1')
	{
		blocked_y = 1;
		g->player.remaining = 96;
		ft_printf("C\n");
	}
	if (g->map.map[(next_y.y + 31)/32][(next_y.x + 31)/32] == '1')
	{
		blocked_y = 1;
		g->player.remaining = 96;
		ft_printf("D\n");
	}
	if (blocked_y)
		g->player.v.y = 0;
	else
	{
		g->player.pos.y += g->player.v.y;
		g->player.remaining += g->player.v.y;
	}
	draw_game(*g);
	return (0);
}

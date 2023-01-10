/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:39:39 by gyoon             #+#    #+#             */
/*   Updated: 2023/01/09 23:20:00 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ft_printf.h"
#include "mlx.h"

void	draw_map(t_game g)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	while (g.map.map[y])
	{
		x = 0;
		while (x < g.map.size.x)
		{
			i = 0;
			if (g.map.map[y][x] == '1')
				i = 1;
			else if (g.map.map[y][x] == 'C')
			{
				if ((g.frame / 8) % 6 == 0 || (g.frame / 8) % 6 == 5)
					i = 10;
				else if ((g.frame / 8) % 6 == 1 || (g.frame / 8) % 6 == 4)
					i = 11;
				else if ((g.frame / 8) % 6 == 2 || (g.frame / 8) % 6 == 3)
					i = 12;
			}
			mlx_put_image_to_window(g.mlx, g.win, g.assets.block[i].img, x * 32, y * 32);
			x++;
		}
		y++;
	}
}

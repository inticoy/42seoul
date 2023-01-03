/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:21:17 by gyoon             #+#    #+#             */
/*   Updated: 2023/01/03 15:52:03 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"
#include "ft_printf.h"

void	draw_map(t_game	g)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	ft_printf("%p\n", g.map.map);
	ft_printf("%p\n", *(g.map.map));
	ft_printf("%p\n", *(g.map.map + 1));
	// while (*g.map.map)
	// {
	// 	x = 0;
	// 	while (x < g.map.size.x)
	// 	{
	// 		if ((*g.map.map)[x] == '1')
	// 			mlx_put_image_to_window(g.mlx, g.win, g.assets.bg.img, \
	// 									x * 32, y * 32);
	// 		else if ((*g.map.map)[x] == '0')
	// 			mlx_put_image_to_window(g.mlx, g.win, g.assets.bg.img, \
	// 									x * 32, y * 32);
	// 		else if ((*g.map.map)[x] == 'C')
	// 			mlx_put_image_to_window(g.mlx, g.win, g.assets.bg.img, \
	// 									x * 32, y * 32);
	// 		x++;
	// 	}
	// 	g.map.map++;
	// 	y++;
	// }
}

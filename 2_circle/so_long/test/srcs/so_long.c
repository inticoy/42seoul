/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:38:06 by gyoon             #+#    #+#             */
/*   Updated: 2023/01/05 15:30:35 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "mlx.h"
#include "so_long.h"

int	main(void)
{
	t_game	g;

	g = init_game();
	mlx_hook(g.win, E_KEY_PRESS, M_KEY_PRESS, hook_key_press, &g);
	mlx_hook(g.win, E_KEY_RELEASE, M_KEY_RELEASE, hook_key_release, &g);
	mlx_loop_hook(g.mlx, hook_loop, &g);
	mlx_loop(g.mlx);
	return (0);
}

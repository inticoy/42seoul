/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_key_press.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 13:34:39 by gyoon             #+#    #+#             */
/*   Updated: 2023/01/05 15:36:43 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ft_printf.h"

int	hook_key_press(int keycode, t_game *game)
{
	if (keycode == KEY_A)
	{
		game->key.press_a = ft_true;
		game->key.press_d = ft_false;
	}
	else if (keycode == KEY_D)
	{
		game->key.press_d = ft_true;
		game->key.press_a = ft_false;
	}
	else if (keycode == KEY_S)
		game->key.press_s = ft_true;
	else if (keycode == KEY_W)
		game->key.press_w = ft_true;
	else if (keycode == KEY_SHIFT)
		game->key.press_shift = ft_true;
	else if (keycode == KEY_ESC)
		game->key.press_esc = ft_true;
	ft_printf("pressed : %d\n", keycode);
	return (0);
}

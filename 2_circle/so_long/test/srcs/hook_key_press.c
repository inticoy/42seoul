/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_key_press.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 13:34:39 by gyoon             #+#    #+#             */
/*   Updated: 2023/01/04 13:46:53 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ft_printf.h"

int	hook_key_press(int keycode, t_game *game)
{
	if (keycode == KEY_A)
		game->key.press_a = ft_true;
	if (keycode == KEY_D)
		game->key.press_d = ft_true;
	if (keycode == KEY_S)
		game->key.press_s = ft_true;
	if (keycode == KEY_W)
		game->key.press_w = ft_true;
	ft_printf("pressed : %d\n", keycode);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:38:06 by gyoon             #+#    #+#             */
/*   Updated: 2023/01/02 16:16:02 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "mlx.h"
#include "so_long.h"

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

int	key_hook(int keycode, int vars)
{
	int	i;

	i = vars;
	i++;
	printf("key : %d\n", keycode);
	return (0);
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	void	*mario;
	int		img_width;
	int		img_height;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1280, 720, "Hello world!");


	mario = mlx_xpm_file_to_image(mlx, "./assets/ch_mario_small_0.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx, mlx_win, mario, 0, 0);

	mlx_key_hook(mlx_win, key_hook, 0);
	mlx_loop(mlx);
	return (0);
}

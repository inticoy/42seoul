/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 20:07:42 by gyoon             #+#    #+#             */
/*   Updated: 2023/01/10 19:29:08 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

t_image	read_image(void *mlx, char *path)
{
	t_image	img;
	int		x;
	int		y;

	img.img = mlx_xpm_file_to_image(mlx, path, &x, &y);
	img.size = init_point(2, x, y, -1);
	return (img);
}

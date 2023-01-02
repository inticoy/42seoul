/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 20:07:42 by gyoon             #+#    #+#             */
/*   Updated: 2023/01/02 20:22:36 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

t_image	read_image(void *mlx, char *path)
{
	t_image	img;

	img.img = mlx_xpm_file_to_image(mlx, path, &img.size.x, &img.size.y);
	return (img);
}

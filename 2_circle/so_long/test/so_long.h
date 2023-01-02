/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:40:52 by gyoon             #+#    #+#             */
/*   Updated: 2023/01/02 22:34:04 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define KEY_A 0
# define KEY_D 2
# define KEY_S 1
# define KEY_W 13

typedef struct s_point	t_size;
typedef struct s_point
{
	char	dimension;
	int		x;
	int		y;
	int		z;
}	t_point;
typedef struct s_image
{
	void		*img;
	t_size		size;
}	t_image;

typedef struct s_assets
{
	t_image	sky;
	t_image	ground;
	t_image	item;
	t_image	stair;
	t_image	wall;
}	t_assets;

typedef struct s_map
{
	char	**map;
	t_size	size;
}	t_map;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_size		size;
	t_map		map;
	t_assets	assets;
}	t_game;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

t_image	read_image(void *mlx, char *path);
t_map	read_map(char *path);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:40:52 by gyoon             #+#    #+#             */
/*   Updated: 2023/01/03 15:27:41 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef FT_NULL
#  define FT_NULL (void *)0
# endif


# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

typedef struct s_point	t_size;
typedef struct s_point	t_point;
struct s_point
{
	char	dimension;
	int		x;
	int		y;
	int		z;
};

typedef struct s_image
{
	void		*img;
	t_size		size;
}	t_image;

typedef struct s_assets
{
	t_image	bg;
	t_image	blocks[5];
	t_image	mario[6];
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

t_map		init_map(void);
t_point		init_point(char dimension, int x, int y, int z);

void		draw_map(t_game	g);


t_assets	read_assets(void *mlx);
t_image		read_image(void *mlx, char *path);
t_map		read_map(char *path);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:40:52 by gyoon             #+#    #+#             */
/*   Updated: 2023/01/02 16:51:04 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define KEY_A 0
# define KEY_D 2
# define KEY_S 1
# define KEY_W 13

typedef struct s_coordinate
{
	int	x;
	int	y;
}	t_coordinate;

typedef struct s_image
{
	void			*img;
	t_coordinate	coord;
}	t_image;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_game
{

}	t_game;

#endif
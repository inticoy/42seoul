/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:41:24 by gyoon             #+#    #+#             */
/*   Updated: 2023/01/03 14:42:43 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_point	init_point(char dimension, int x, int y, int z)
{
	t_point	point;

	point.dimension = dimension;
	point.x = x;
	point.y = y;
	point.z = z;
	return (point);
}

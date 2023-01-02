/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 20:26:13 by gyoon             #+#    #+#             */
/*   Updated: 2023/01/02 23:09:50 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "so_long.h"
#include "get_next_line.h"
#include "ft_printf.h"

t_map	read_map(char *path)
{
	int		fd;
	int		line;
	int		i;
	t_map	map;

	line = 0;
	i = 0;
	fd = open(path, O_RDONLY);
	map.size.x = 0;
	/* while (!get_next_line(fd))
		line++;
	close(fd);
	map.map = (char **)ft_calloc(line, sizeof(char *));
	fd = open(path, O_RDONLY);
	while (i < line)
		map.map[i++] = get_next_line(fd);
	map.size.dimension = 2;
	map.size.x = ft_strlen(map.map[1]);
	map.size.y = line;
	map.size.z = 0; */
	return (map);
}

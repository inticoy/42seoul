/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 20:26:13 by gyoon             #+#    #+#             */
/*   Updated: 2023/01/03 22:04:36 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "so_long.h"
#include "get_next_line.h"
#include "ft_printf.h"

static int	get_num_line(char *path)
{
	int		fd;
	char	*line;
	int		ret;

	fd = open(path, O_RDONLY);
	ret = 0;
	while (ft_true)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		else
		{
			ret++;
			ft_free_s(line);
		}
	}
	close(fd);
	return (ret);
}

t_map	read_map(char *path)
{
	int		fd;
	int		i;
	char	*line;
	t_map	map;

	map = init_map();
	map.size.y = get_num_line(path);
	map.map = (char **)ft_calloc(map.size.y + 1, sizeof(char *));
	fd = open(path, O_RDONLY);
	i = 0;
	while (i < map.size.y)
		map.map[i++] = get_next_line(fd);
	map.size.x = ft_strlen(map.map[0]) - 1;
	close (fd);
	return (map);
}

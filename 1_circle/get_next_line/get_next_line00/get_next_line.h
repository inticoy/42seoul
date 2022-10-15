/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:06:54 by gyoon             #+#    #+#             */
/*   Updated: 2022/10/15 20:46:32 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

// just for test, erase when commit.
# define BUFFER_SIZE 42 

typedef struct s_buffer
{
	char buffer[BUFFER_SIZE];
	int  index;
    int  length;
} t_buffer;

typedef struct s_string
{
		char *string;
		int  length;
} t_string;

char	*get_next_line(int fd);

#endif
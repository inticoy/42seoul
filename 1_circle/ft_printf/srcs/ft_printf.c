/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:10:39 by gyoon             #+#    #+#             */
/*   Updated: 2022/11/21 13:14:16 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "libft/libft.h"
#include <stdio.h>

typedef enum e_bool {
	false,
	true
}	t_bool;

typedef struct s_flag {
	t_bool	left;
	t_bool	sign;
	t_bool	space;
	t_bool	prefix;
	t_bool	zero;
}	t_flag;
typedef struct s_format {


}	t_format;

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		total;

	va_start(args, fmt);
	total = 0;
	while (*fmt)
	{
		write(1, fmt++, 1);
		total++;
	}
	va_end(args);
	return (total);
}

int	main(void)
{
	int	n;

	n = ft_printf("hello\n");
	printf("%-#.4x\n", -333);
	return (0);
}

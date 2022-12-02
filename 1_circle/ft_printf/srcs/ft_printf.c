/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:10:39 by gyoon             #+#    #+#             */
/*   Updated: 2022/11/14 15:54:50 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "libft/libft.h"
#include <stdio.h>

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
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 18:34:21 by gyoon             #+#    #+#             */
/*   Updated: 2022/09/08 18:54:59 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putunbr_fd(unsigned int un, int fd)
{
	char	digit;

	digit = '0' + un % 10;
	if (un >= 10)
		ft_putunbr_fd(un / 10, fd);
	write(fd, &digit, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		write(fd, "-", 1);
		ft_putunbr_fd(-n, fd);
	}
	else
		ft_putunbr_fd(n, fd);
}

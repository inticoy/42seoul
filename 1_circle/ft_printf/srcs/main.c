/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:26:15 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/17 11:53:15 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <unistd.h>

int	main(void)
{
	int	ft;
	int	or;

	ft = ft_printf("%05d\n", 12);
	or = printf("%05d\n", 12);

	printf("%d %d\n", ft, or);
	return (0);
}

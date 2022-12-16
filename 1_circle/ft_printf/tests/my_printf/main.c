/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:26:15 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/16 21:31:39 by gyoon            ###   ########.fr       */
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

	ft = ft_printf("\001\002\007\v\010\f\r\n");
	or = printf("\001\002\007\v\010\f\r\n");

	printf("%d %d\n", ft, or);
	return (0);
}

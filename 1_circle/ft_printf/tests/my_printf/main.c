/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:26:15 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/05 15:59:48 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	ft;
	int	or;

	ft = ft_printf("hello world!%d %d %d\n", 123, 45, 678);
	or = printf("hello world!%d %d %d\n", 123, 45, 678);
	printf("%d vs %d\n", ft, or);
	return (0);
}

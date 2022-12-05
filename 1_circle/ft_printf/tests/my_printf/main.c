/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:26:15 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/05 23:05:30 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	ft;
	int	or;

	ft_printf("hello world!\n");
	ft_printf("%c\n", '&');
	ft_printf("%s\n", "testing %s");
	ft_printf("%p\n", &ft);
	ft_printf("%d\n", 123);
	ft_printf("%i\n", 123);
	ft_printf("%u\n", -123);
	ft_printf("%x\n", 123);
	ft_printf("%X\n", 123);
	ft_printf("%%\n");
	ft_printf("----- ----- ----- -----\n");
	printf("hello world!\n");
	printf("%c\n", '&');
	printf("%s\n", "testing %s");
	printf("%p\n", &ft);
	printf("%d\n", 123);
	printf("%i\n", 123);
	printf("%u\n", -123);
	printf("%x\n", 123);
	printf("%X\n", 123);
	printf("%%\n");
	printf("----- ----- ----- -----\n");
	return (0);
}

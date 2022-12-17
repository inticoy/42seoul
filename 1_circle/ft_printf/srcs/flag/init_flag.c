/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 15:41:02 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/17 12:47:03 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag	init_flag(void)
{
	t_flag	flag;

	flag.left = 0;
	flag.sign = 0;
	flag.space = 0;
	flag.prefix = 0;
	flag.zero = 0;
	return (flag);
}

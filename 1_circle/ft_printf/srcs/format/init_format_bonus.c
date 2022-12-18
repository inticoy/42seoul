/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_format_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 15:39:53 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/17 15:46:42 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

t_format	init_format(void)
{
	t_format	format;

	format.len = 0;
	format.flag = init_flag();
	format.width = 0;
	format.precision = -1;
	format.specifier = 0;
	return (format);
}

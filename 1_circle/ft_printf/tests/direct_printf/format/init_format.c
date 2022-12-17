/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 15:39:53 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/14 15:28:40 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format	init_format(void)
{
	t_format	format;

	format.len = 0;
	format.flag = init_flag();
	format.width = 0;
	format.precision = 0;
	format.specifier = 0;
	return (format);
}

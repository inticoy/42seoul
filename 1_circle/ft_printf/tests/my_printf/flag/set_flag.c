/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_flag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 23:29:47 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/05 23:30:03 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_flag(t_flag *flag, int c)
{
	if (c == '-')
		flag->left = FT_TRUE;
	else if (c == '+')
		flag->sign = FT_TRUE;
	else if (c == ' ')
		flag->space = FT_TRUE;
	else if (c == '#')
		flag->prefix = FT_TRUE;
	else if (c == '0')
		flag->zero = FT_TRUE;
}

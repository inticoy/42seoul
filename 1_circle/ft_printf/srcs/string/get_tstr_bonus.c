/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tstr_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 00:30:47 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/17 15:46:33 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

t_string	get_tstr(char *str, int len, int size)
{
	t_string	tstr;

	if (!str)
	{
		tstr.str = str;
		tstr.len = -1;
		tstr.size = 0;
	}
	else
	{
		tstr.str = str;
		tstr.len = len;
		tstr.size = size;
	}
	return (tstr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 00:30:47 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/17 00:30:57 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_string	get_tstr(char *str, int len, int size)
{
	t_string	tstr;

	tstr.str = str;
	tstr.len = len;
	tstr.size = size;
	return (tstr);
}
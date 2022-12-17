/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtotstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:03:43 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/17 01:03:18 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_string	ft_strtotstr(char *str)
{
	t_string	tstr;

	if (!str)
		return (get_tstr(FT_NULL, -1, 0));
	else
		return (get_tstr(str, ft_strlen(str), ft_strlen(str) + 1));
}

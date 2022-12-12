/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   need_padding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:59:55 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/12 20:00:13 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_bool	need_padding(char *str, t_format format)
{
	if (format.width <= ft_strlen(str))
		return (ft_false);
	else
		return (ft_true);
}
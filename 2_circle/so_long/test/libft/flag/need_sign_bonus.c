/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   need_sign_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:42:43 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/17 15:46:58 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

t_bool	need_sign(t_format format)
{
	if (!format.flag.sign)
		return (ft_false);
	else if (format.specifier == 'd')
		return (ft_true);
	else if (format.specifier == 'i')
		return (ft_true);
	else
		return (ft_false);
}

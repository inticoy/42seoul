/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_sign.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:53:09 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/12 19:46:49 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*sign(char *str, t_format format)
{
	char	*ret;

	if (ft_isminus(str[0]))
		return (str);
	else
	{
		ret = ft_strjoin("+", str);
		ft_free_s(str);
		return (ret);
	}
}

char	*convert_sign(char *str, t_format format)
{
	if (!str)
		return (FT_NULL);
	else if (!need_sign(format))
		return (str);
	else
		return (sign(str, format));
}

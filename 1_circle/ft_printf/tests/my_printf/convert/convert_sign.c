/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_sign.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:53:09 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/12 16:33:17 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_bool	need_sign(char *str, t_format format)
{
	if (format.specifier == 'd')
		return (ft_true);
	else if (format.specifier == 'i')
		return (ft_true);
	else
		return (ft_false);
}

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
	else if (!need_sign(str, format))
		return (str);
	else if (!format.flag.sign)
		return (str);
	else
		return (sign(str, format));
}

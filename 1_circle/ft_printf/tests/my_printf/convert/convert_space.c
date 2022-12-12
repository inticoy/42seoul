/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_space.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:53:09 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/12 19:46:28 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*space(char *str, t_format format)
{
	char	*ret;

	if (ft_isplus(str[0]) || ft_isminus(str[0]))
		return (str);
	else
	{
		ret = ft_strjoin(" ", str);
		ft_free_s(str);
		return (ret);
	}
}

char	*convert_space(char *str, t_format format)
{
	if (!str)
		return (FT_NULL);
	else if (!need_space(format))
		return (str);
	else if (!format.flag.space)
		return (str);
	else
		return (space(str, format));
}

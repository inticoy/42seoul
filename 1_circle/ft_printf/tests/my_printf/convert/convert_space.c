/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_space.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:53:09 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/12 18:47:15 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_bool	need_space(char *str, t_format format)
{
	if (format.specifier == 'd')
		return (ft_true);
	else if (format.specifier == 'i')
		return (ft_true);
	else
		return (ft_false);
}

static char	*space(char *str, t_format format)
{
	char	*ret;

	if (!ft_isplus(str[0]) && !ft_isminus(str[0]))
		ret = ft_strjoin(" ", str);
	ft_free_s(str);
	return ();
}

char	*convert_space(char *str, t_format format)
{
	if (!str)
		return (FT_NULL);
	else if (!need_space(str, format))
		return (str);
	else if (!format.flag.space)
		return (str);
	else
		return (space(str, format));


	if (format.specifier == 'd' || format.specifier == 'i')
		if (!ft_isplus(str[0]) && !ft_isminus(str[0]))
			ret = ft_strjoin(" ", str);
	else
		return (str);
	ft_free_s(str);
	return (ret);
}

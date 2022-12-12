/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_prefix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:53:09 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/12 19:46:44 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*prefix(char *str, t_format format)
{
	char	*ret;

	if (format.specifier == 'x')
		ret = ft_strjoin("0x", str);
	else if (format.specifier == 'X')
		ret = ft_strjoin("0X", str);
	ft_free_s(str);
	return (ret);
}

char	*convert_prefix(char *str, t_format format)
{
	char	*ret;

	if (!str)
		return (FT_NULL);
	else if (!need_prefix(format))
		return (str);
	else
		return (prefix(str, format));
}

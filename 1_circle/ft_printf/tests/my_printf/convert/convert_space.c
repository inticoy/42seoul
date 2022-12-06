/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_space.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:53:09 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/06 22:00:50 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*convert_space(char *str, t_format *format)
{
	char	*ret;

	if (!str || !format)
		return (FT_NULL);
	if (format->specifier == 'd' || format->specifier == 'i')
	{
		if (!ft_isplus(str[0]) && !ft_isminus(str[0]))
		{
			ret = ft_strjoin(" ", str);
			free(str);
			return (str);
		}
	}
	return (ret);
}

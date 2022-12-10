/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_sign.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:53:09 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/10 15:54:13 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*convert_sign(char *str, t_format format)
{
	char	*ret;

	if (!str)
		return (FT_NULL);
	if (format.specifier == 'd' || format.specifier == 'i')
	{
		if (!ft_isminus(str[0]))
		{
			ret = ft_strjoin("+", str);
			free(str);
			return (ret);
		}
	}
	return (str);
}

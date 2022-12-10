/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_prefix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:53:09 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/10 15:53:59 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*convert_prefix(char *str, t_format format)
{
	char	*ret;

	if (!str)
		return (FT_NULL);
	if (format.specifier == 'x')
		ret = ft_strjoin("0x", str);
	else if (format.specifier == 'X')
		ret = ft_strjoin("0X", str);
	free(str);
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_padding.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:53:09 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/10 18:17:16 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*convert_padding(char *str, t_format format)
{
	char	*ret;

	if (!str)
		return (FT_NULL);
	if (format.width <= ft_strlen(str))
		return (str);
	else
		ret = (char *)ft_calloc(format.width + 1, sizeof(char));
	if (!ret)
		return (FT_NULL);
	if (format.flag.zero)
		ft_bzero(ret, format.width);
	else
		ft_bspace(ret, format.width);
	if (format.flag.left)
		ft_memcpy(ret, str, ft_strlen(str));
	else
		ft_memcpy(ret + format.width - ft_strlen(str), str, ft_strlen(str));
	return (ret);
}

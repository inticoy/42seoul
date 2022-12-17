/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tstrnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:15:09 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/16 13:34:09 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_string	*ft_tstrnew(char *str, int len, int size)
{
	t_string	*tstr;

	if (!str)
		return (FT_NULL);
	tstr = (t_string *)ft_calloc(1, sizeof(t_string));
	if (!tstr)
	{
		ft_free_s(str);
		return (FT_NULL);
	}
	tstr->str = str;
	tstr->len = len;
	tstr->size = size;
	return (tstr);
}

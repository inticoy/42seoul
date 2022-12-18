/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tstrjoin_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:36:58 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/17 15:46:28 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

t_string	ft_tstrjoin(t_string ts1, t_string ts2)
{
	char	*str;

	if (!ts1.str || !ts2.str)
		return (get_tstr(FT_NULL, -1, 0));
	str = (char *)ft_calloc(ts1.size + ts2.size - 1, sizeof(char));
	if (!str)
		return (get_tstr(FT_NULL, -1, 0));
	ft_memcpy(str, ts1.str, ts1.len);
	ft_memcpy(str + ts1.len, ts2.str, ts2.len);
	return (get_tstr(str, ts1.len + ts2.len, ts1.size + ts2.size - 1));
}

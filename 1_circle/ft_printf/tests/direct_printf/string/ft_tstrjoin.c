/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tstrjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:36:58 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/15 22:24:41 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

t_string	*ft_tstrjoin(t_string *ts1, t_string *ts2)
{
	t_string	*ret;

	if (!ts1 || !ts2)
		return (FT_NULL);
	ret = (t_string *)ft_calloc(1, sizeof(t_string));
	if (!ret)
		return (FT_NULL);
	ret->len = ts1->len + ts2->len;
	ret->size = ts1->size + ts2->size - 1;
	ret->str = (char *)ft_calloc(ret->size, sizeof(char));
	if (!ret->str)
	{
		del_tstr(ret);
		return (FT_NULL);
	}
	ft_memcpy(ret->str, ts1->str, ts1->len);
	ft_memcpy(ret->str + ts1->len, ts2->str, ts2->len);
	return (ret);
}
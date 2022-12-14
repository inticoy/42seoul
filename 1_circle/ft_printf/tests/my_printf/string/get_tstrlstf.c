/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tstrlstf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 23:12:40 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/14 15:13:15 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

t_list	*get_tstrlstf(const char *fmt, va_list *args)
{
	t_format	format;
	t_string	*tstr;
	t_list		*snode;
	t_list		*shead;

	shead = FT_NULL;
	while (*fmt)
	{
		format = get_formatf(fmt);
		tstr = get_tstrf(fmt, format, args);
		snode = ft_lstnew(tstr);
		if (!tstr || !snode)
		{
			del_tstr(tstr);
			ft_free_s(snode);
			ft_lstclear(&shead, ft_free_s);
			return (FT_NULL);
		}
		if (!shead)
			shead = snode;
		else
			ft_lstadd_back(&shead, snode);
		fmt += format.len;
	}
	return (shead);
}

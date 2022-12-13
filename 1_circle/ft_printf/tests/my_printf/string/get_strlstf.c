/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_strlstf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 23:12:40 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/13 15:35:07 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

t_list	*get_strlstf(const char *fmt, va_list *args)
{
	t_format	format;
	char		*str;
	t_list		*snode;
	t_list		*shead;

	shead = FT_NULL;
	while (*fmt)
	{
		format = get_formatf(fmt);
		str = get_strf(fmt, format, args);
		snode = ft_lstnew(str);
		if (!str || !snode)
		{
			ft_free_s(str);
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

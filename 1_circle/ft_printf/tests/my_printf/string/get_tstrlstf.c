/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tstrlstf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 23:12:40 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/16 19:31:40 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static t_string	*get_tstr_empty(void)
{
	t_string	*tstr;

	tstr = (t_string *)ft_calloc(1, sizeof(t_string));
	if (!tstr)
		return (FT_NULL);
	tstr->str = (char *)ft_calloc(1, sizeof(char));
	if (!tstr->str)
	{
		del_tstr(tstr);
		return (FT_NULL);
	}
	tstr->len = 0;
	tstr->size = 1;
	return (tstr);
}

static t_list	*get_shead(void)
{
	t_string	*snode;
	t_list		*shead;

	snode = get_tstr_empty();
	if (!snode)
		return (FT_NULL);
	shead = ft_lstnew(snode);
	if (!shead)
	{
		del_tstr(snode);
		return (FT_NULL);
	}
	return (shead);
}

t_list	*get_tstrlstf(const char *fmt, va_list *args)
{
	t_format	format;
	t_string	*tstr;
	t_list		*snode;
	t_list		*shead;

	shead = get_shead();
	if (!shead)
		return (FT_NULL);
	while (*fmt)
	{
		format = get_formatf(fmt);
		tstr = get_tstrf(fmt, format, args);
		if (!tstr)
		{
			ft_lstclear(&shead, (void (*)(void *))del_tstr);
			return (FT_NULL);
		}
		snode = ft_lstnew(tstr);
		if (!tstr || !snode)
		{
			del_tstr(tstr);
			ft_free_s(snode);
			ft_lstclear(&shead, (void (*)(void *))del_tstr);
			return (FT_NULL);
		}
		ft_lstadd_back(&shead, snode);
		fmt += format.len;
	}
	return (shead);
}

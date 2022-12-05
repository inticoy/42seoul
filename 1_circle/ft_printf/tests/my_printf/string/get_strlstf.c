/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_strlstf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 23:12:40 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/05 23:13:02 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

t_list	*get_strlstf(const char *fmt, t_list *formats, va_list args)
{
	t_list		*shead;
	t_list		*snode;
	char		*str;

	shead = FT_NULL;
	while (*fmt && formats)
	{
		str = get_strf(fmt, formats->content, args);
		snode = ft_lstnew(str);
		if (!str || !snode)
		{
			if (str)
				free(str);
			ft_lstclear(&shead, free);
			return (FT_NULL);
		}
		if (!shead)
			shead = snode;
		else
			ft_lstadd_back(&shead, snode);
		fmt += ((t_format *)formats->content)->len;
		formats = formats->next;
	}
	return (shead);
}

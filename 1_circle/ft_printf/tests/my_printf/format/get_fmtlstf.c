/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fmtlstf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 23:27:05 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/05 23:27:28 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

t_list	*get_fmtlstf(const char *fmt)
{
	t_list		*fhead;
	t_list		*fnode;
	t_format	*format;

	fhead = FT_NULL;
	while (*fmt)
	{
		format = get_fmtf(fmt);
		fnode = ft_lstnew(format);
		if (!format || !fnode)
		{
			if (format)
				free(format);
			ft_lstclear(&fhead, (void (*)(void *))del_fmtnode);
			return (FT_NULL);
		}
		if (!fhead)
			fhead = fnode;
		else
			ft_lstadd_back(&fhead, fnode);
		fmt += format->len;
	}
	return (fhead);
}

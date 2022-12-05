/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:27:41 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/05 16:56:06 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>

int	ft_strlstlen(t_list *strlst)
{
	int	len;

	len = 0;
	while (strlst)
	{
		len += ft_strlen(strlst->content);
		strlst = strlst->next;
	}
	return (len);
}

char	*get_strf(const char *fmt, t_format *format, va_list args)
{
	char	*str;

	if (!format->specifier)
	{
		str = ft_calloc(format->len + 1, sizeof(char));
		ft_strlcpy(str, fmt, format->len + 1);
	}
	else if (format->specifier == 'd')
		str = ft_itoa(va_arg(args, int));
	return (str);
}

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
		if (!shead)
			shead = snode;
		else
			ft_lstadd_back(&shead, snode);
		fmt += ((t_format *)formats->content)->len;
		formats = formats->next;
	}
	return (shead);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formats.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:28:36 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/05 16:56:30 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

t_format	*ft_fmtnew(void)
{
	t_format	*fmt;

	fmt = (t_format *)ft_calloc(1, sizeof(t_format));
	if (!fmt)
		return (FT_NULL);
	fmt->flag = (t_flag *)ft_calloc(1, sizeof(t_flag));
	if (!fmt->flag)
	{
		free(fmt);
		return (FT_NULL);
	}
	return (fmt);
}

void	set_flag(t_flag *flag, int c)
{
	if (c == '-')
		flag->left = FT_TRUE;
	else if (c == '+')
		flag->sign = FT_TRUE;
	else if (c == ' ')
		flag->space = FT_TRUE;
	else if (c == '#')
		flag->prefix = FT_TRUE;
	else if (c == '0')
		flag->zero = FT_TRUE;
}

t_format	*get_fmtf(const char *fmt)
{
	t_format	*format;
	int			len;

	format = ft_fmtnew();
	len = 0;
	if (ft_ispercent(fmt[len]))
	{
		while (ft_isflag(fmt[++len]))
			set_flag(format->flag, fmt[len]);
		format->width = ft_atoi(fmt);
		len += get_skip_digit(fmt + len);
		if (ft_isdot(fmt[len]))
		{
			format->precision = ft_atoi(fmt + ++len);
			len += get_skip_digit(fmt + len);
		}
		format->specifier = fmt[len++];
	}
	else
		while (fmt[len] && !ft_ispercent(fmt[len]))
			len++;
	format->len = len;
	return (format);
}

void	del_fmtnode(t_format *format)
{
	if (format->flag)
		free(format->flag);
	free(format);
}

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
			return (0);
		}
		if (!fhead)
			fhead = fnode;
		else
			ft_lstadd_back(&fhead, fnode);
		fmt += format->len;
	}
	return (fhead);
}

// printf("\nfmtnew : %d, %d, %d, %d\n", format->len, format->width, format->precision, format->specifier);
// printf("flags : %d, %d, %d, %d, %d\n", format->flag->left, format->flag->sign, format->flag->space, format->flag->prefix, format->flag->zero);


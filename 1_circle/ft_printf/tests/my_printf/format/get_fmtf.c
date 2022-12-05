/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fmtf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 23:28:42 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/05 23:29:22 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

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

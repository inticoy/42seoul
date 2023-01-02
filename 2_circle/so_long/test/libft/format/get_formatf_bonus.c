/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_formatf_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 17:20:54 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/17 15:46:41 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	isflag(int c)
{
	if (c == '-' || c == '+' || c == ' ' || c == '#' || c == '0')
		return (1);
	else
		return (0);
}

t_format	get_formatf(const char *fmt)
{
	t_format	format;

	format = init_format();
	if (fmt[format.len] == '%')
	{
		while (isflag(fmt[++format.len]))
			format.flag = update_flag(format.flag, fmt[format.len]);
		format.width = ft_atoi(fmt + format.len);
		while (ft_isdigit(fmt[format.len]))
			format.len++;
		if (fmt[format.len] == '.')
		{
			format.precision = ft_atoi(fmt + ++format.len);
			while (ft_isdigit(fmt[format.len]))
				format.len++;
		}
		format.specifier = fmt[format.len++];
	}
	else
		while (fmt[format.len] && fmt[format.len] != '%')
			format.len++;
	return (format);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tstrlstf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 23:12:40 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/16 22:01:02 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int	get_tstrlstf(const char *fmt, va_list *args)
{
	t_format	format;
	t_string	*tstr;
	int			wret;
	int			printed;

	tstr = 0;
	printed = 0;
	while (*fmt)
	{
		format = get_formatf(fmt);
		if (!format.specifier)
		{
			wret = write(1, fmt, format.len);
			if (wret < 0)
				return (-1);
		}
		else
		{
			tstr = get_tstrf(fmt, format, args);
			if (!tstr)
				return (-1);
			wret = write(1, tstr->str, tstr->len);
			if (wret < 0)
			{
				del_tstr(tstr);
				return (-1);
			}
			del_tstr(tstr);
			tstr = 0;
		}
		fmt += format.len;
		printed += wret;
	}
	return (printed);
}

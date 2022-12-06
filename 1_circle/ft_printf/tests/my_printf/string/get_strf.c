/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_strf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 23:13:18 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/06 22:21:58 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

char	*get_strf(const char *fmt, t_format *format, va_list args)
{
	char	*str;

	if (!format->specifier)
		str = ft_strndup(fmt, format->len);
	else
	{
		str = ft_vtoa(format->specifier, args);
		if (format->precision >= 0)
			str = convert_precision(str, format);
		if (format->flag->prefix)
			str = convert_prefix(str, format);
		if (format->flag->sign)
			str = convert_sign(str, format);
		if (format->flag->space)
			str = convert_space(str, format);
		str = convert_padding(str, format);
	}
	return (str);
}

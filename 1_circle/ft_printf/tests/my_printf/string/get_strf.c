/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_strf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 23:13:18 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/13 15:44:21 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

char	*get_strf(const char *fmt, t_format format, va_list *args)
{
	char	*str;

	if (!format.specifier)
		str = ft_strndup(fmt, format.len);
	else
	{
		str = ft_vtoa(format.specifier, args);
		// str = convert_precision(str, format);
		// str = convert_prefix(str, format);
		// str = convert_sign(str, format);
		// str = convert_space(str, format);
		// str = convert_padding(str, format);
	}
	return (str);
}

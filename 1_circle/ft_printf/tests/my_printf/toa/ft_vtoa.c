/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 23:14:08 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/05 23:17:18 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

#include "libft.h"
#include "ft_printf.h"

char	*ft_vtoa(t_format *format, va_list args)
{
	char		*str;

	if (format->specifier == 'c')
		str = ft_ctoa(va_arg(args, int));
	else if (format->specifier == 's')
		str = ft_strdup(va_arg(args, char *));
	else if (format->specifier == 'p')
		str = ft_ptoa(va_arg(args, void *));
	else if (format->specifier == 'd' || format->specifier == 'i')
		str = ft_itoa(va_arg(args, int));
	else if (format->specifier == 'u')
		str = ft_utoa(va_arg(args, unsigned int));
	else if (format->specifier == 'x')
		str = ft_xtoa(va_arg(args, int));
	else if (format->specifier == 'X')
		str = ft_strtoupper(ft_xtoa(va_arg(args, int)));
	else if (format->specifier == '%')
		str = ft_strdup("%");
	return (str);
}

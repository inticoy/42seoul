/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 23:14:08 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/06 18:56:58 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

#include "libft.h"
#include "ft_printf.h"

char	*ft_vtoa(char specifier, va_list args)
{
	char		*str;

	if (specifier == 'c')
		str = ft_ctoa(va_arg(args, int));
	else if (specifier == 's')
		str = ft_strdup(va_arg(args, char *));
	else if (specifier == 'p')
		str = ft_ptoa(va_arg(args, void *));
	else if (specifier == 'd')
		str = ft_itoa(va_arg(args, int));
	else if (specifier == 'i')
		str = ft_itoa(va_arg(args, int));
	else if (specifier == 'u')
		str = ft_utoa(va_arg(args, unsigned int));
	else if (specifier == 'x')
		str = ft_xtoa(va_arg(args, int));
	else if (specifier == 'X')
		str = ft_strtoupper(ft_xtoa(va_arg(args, int)));
	else if (specifier == '%')
		str = ft_strdup("%");
	if (!str)
		return (FT_NULL);
	return (str);
}

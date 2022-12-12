/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 23:14:08 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/12 20:03:36 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

#include "libft.h"
#include "ft_printf.h"

char	*ft_vtoa(char specifier, va_list args)
{
	char	*str;
	void	*pa;

	if (specifier == 's')
		pa = va_arg(args, void *);
	if (specifier == 'c')
		str = ft_ctoa(va_arg(args, int));
	else if (specifier == 's' && !pa)
		str = ft_strdup("(null)");
	else if (specifier == 's' && pa)
		str = ft_strdup(pa);
	else if (specifier == 'p')
		str = ft_ptoa(va_arg(args, void *));
	else if (specifier == 'd' || specifier == 'i')
		str = ft_itoa(va_arg(args, int));
	else if (specifier == 'u')
		str = ft_utoa(va_arg(args, unsigned int));
	else if (specifier == 'x')
		str = ft_xtoa(va_arg(args, int));
	else if (specifier == 'X')
		str = ft_strtoupper(ft_xtoa(va_arg(args, int)));
	else if (specifier == '%')
		str = ft_strdup("%");
	return (str);
}

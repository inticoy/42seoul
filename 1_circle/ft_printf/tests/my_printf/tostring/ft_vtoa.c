/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 23:14:08 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/16 15:55:19 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

#include "libft.h"
#include "ft_printf.h"

#include <stdio.h>

t_string	*ft_vtoa(char specifier, va_list *args)
{
	t_string	*tstr;
	void		*pa;

	if (specifier == 's')
		pa = va_arg(*args, void *);
	if (specifier == 'c')
		tstr = ft_tstrnew(ft_ctoa(va_arg(*args, int)), 1, 2);
	else if (specifier == 's' && !pa)
		tstr = ft_strtotstr(ft_strdup("(null)"));
	else if (specifier == 's' && pa)
		tstr = ft_strtotstr(ft_strdup(pa));
	else if (specifier == 'p')
		tstr = ft_strtotstr(ft_ptoa(va_arg(*args, void *)));
	else if (specifier == 'd' || specifier == 'i')
		tstr = ft_strtotstr(ft_itoa(va_arg(*args, int)));
	else if (specifier == 'u')
		tstr = ft_strtotstr(ft_utoa(va_arg(*args, unsigned int)));
	else if (specifier == 'x')
		tstr = ft_strtotstr(ft_xtoa(va_arg(*args, unsigned int)));
	else if (specifier == 'X')
		tstr = ft_strtotstr(ft_strtoupper(ft_xtoa(va_arg(*args, int))));
	else if (specifier == '%')
		tstr = ft_strtotstr(ft_strdup("%"));
	return (tstr);
}

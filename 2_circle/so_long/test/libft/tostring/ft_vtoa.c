/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 23:14:08 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/17 15:30:02 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_string	ft_vtoa(char specifier, va_list *args)
{
	t_string	tstr;
	void		*pa;

	tstr = get_tstr_auto(FT_NULL);
	if (specifier == 's')
		pa = va_arg(*args, void *);
	if (specifier == 'c')
		tstr = get_tstr(ft_ctoa(va_arg(*args, int)), 1, 2);
	else if (specifier == 's' && !pa)
		tstr = get_tstr_auto(ft_strdup("(null)"));
	else if (specifier == 's' && pa)
		tstr = get_tstr_auto(ft_strdup(pa));
	else if (specifier == 'p')
		tstr = get_tstr_auto(ft_ptoa(va_arg(*args, void *)));
	else if (specifier == 'd' || specifier == 'i')
		tstr = get_tstr_auto(ft_itoa(va_arg(*args, int)));
	else if (specifier == 'u')
		tstr = get_tstr_auto(ft_utoa(va_arg(*args, unsigned int)));
	else if (specifier == 'x')
		tstr = get_tstr_auto(ft_xtoa(va_arg(*args, unsigned int)));
	else if (specifier == 'X')
		tstr = get_tstr_auto(ft_strtoupper(ft_xtoa(va_arg(*args, int))));
	else if (specifier == '%')
		tstr = get_tstr_auto(ft_strdup("%"));
	return (tstr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 21:34:02 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/16 00:18:18 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <unistd.h>
#include <stdarg.h>

int	get_skip_digit(const char *str)
{
	int	len;

	len = 0;
	while (ft_isdigit(str[len]))
		len++;
	return (len);
}

void	prints(t_string *tstr)
{
	write(1, tstr->str, tstr->len);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	t_list	*tstrlst;
	int		printed;

	va_start(args, fmt);
	tstrlst = get_tstrlstf(fmt, &args);
	if (!tstrlst)
		return (-1);
	printed = print_tstrlst(tstrlst);
	ft_lstclear(&tstrlst, (void (*)(void *))del_tstr);
	va_end(args);
	return (printed);
}

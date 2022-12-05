/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 21:34:02 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/05 16:57:50 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>
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

void	prints(char *str)
{
	write(1, str, ft_strlen(str));
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	t_list	*fmtlst;
	t_list	*strlst;
	int		printed;

	va_start(args, fmt);
	fmtlst = get_fmtlstf(fmt);
	strlst = get_strlstf(fmt, fmtlst, args);
	ft_lstiter(strlst, (void (*)(void *))prints);
	printed = ft_strlstlen(strlst);
	va_end(args);
	return (printed);
}

//printf("fs : %d\n", ft_lstsize(fmtlst));
//printf("ss : %d\n", ft_lstsize(strlst));

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:10:39 by gyoon             #+#    #+#             */
/*   Updated: 2022/11/10 22:09:00 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "libft/libft.h"

int	ft_printf(const char *f, ...)
{
	int	len;

	len = 0;
	while (*f)
	{
		write(1, f++, 1);
		len++;
	}
	return (len);
}

#include <stdio.h>

int main(void)
{
	int n = ft_printf("hello\n");
	printf("%d\n", n);
	return (0);
}
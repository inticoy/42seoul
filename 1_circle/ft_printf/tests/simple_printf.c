/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_printf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:12:05 by gyoon             #+#    #+#             */
/*   Updated: 2022/11/14 20:59:34 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

void	testf(const char *fmt, ...)
{
	va_list	args;

	va_start(args, fmt);
	printf("@%p\n", args);
	while (*fmt != '\0')
	{
		if (*fmt == 'd')
		{
			int i = va_arg(args, int);
			printf("%d\n", i);
		}
		else if (*fmt == 'c')
		{
			char c = va_arg(args, char);
			printf("%d\n", c);
		}
		else if (*fmt == 'f')
		{
			double d = va_arg(args, double);
			printf("%f\n", d);
		}
		++fmt;
	}
	va_end(args);
}

int main(void)
{
	testf("dcf", 10, 'c', 1.4);
	return (0);
}
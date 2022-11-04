/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:23:02 by gyoon             #+#    #+#             */
/*   Updated: 2022/11/04 20:13:07 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_digits(int n)
{
	if (0 <= n && n < 10)
		return (1);
	else
		return (get_digits(n / 10) + 1);
}

static void	set_itoa(char *s, int n)
{
	if (-10 < n && n < 0)
		*(s - 1) = '-';
	if (n < 0)
		*s = '0' - n % 10;
	else
		*s = '0' + n % 10;
	if (10 <= n || n <= -10)
		set_itoa(s - 1, n / 10);
}

char	*ft_itoa(int n)
{
	const size_t	digits = get_digits(n);
	char			*ret;

	ret = (char *) ft_calloc(digits + 1, sizeof(char));
	if (!ret)
		return (0);
	set_itoa(ret + digits - 1, n);
	return (ret);
}

// #include <stdio.h>
// #include <limits.h>

// int main(void)
// {
// 	printf("%s\n", ft_itoa(0));
// 	printf("%s\n", ft_itoa(5));
// 	printf("%s\n", ft_itoa(55));
// 	printf("%s\n", ft_itoa(INT_MAX));
// 	printf("%s\n", ft_itoa(0));
// 	printf("%s\n", ft_itoa(-5));
// 	printf("%s\n", ft_itoa(-55));
// 	printf("%s\n", ft_itoa(INT_MIN));
// 	return (0);
// }

// static void	set_itoa(char *s, int n)
// {
// 	if (10 <= n || n <= -10)
// 		set_itoa(s, n / 10);
// 	if (n < 0)
// 	{
// 		*s = '-';
// 		*(s + get_digits(n) - 1) = '0' - (n % 10);
// 	}
// 	else
// 		*(s + get_digits(n) - 1) = '0' + (n % 10);

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 23:06:11 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/10 19:06:17 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

char	*ft_strtoupper(char *s)
{
	size_t	len;
	size_t	i;

	if (!s)
		return (FT_NULL);
	len = ft_strlen(s);
	i = 0;
	while (i < len)
	{
		s[i] = ft_toupper(s[i]);
		i++;
	}
	return (s);
}

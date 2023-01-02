/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 20:11:53 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/17 15:29:33 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ctoa(int c)
{
	char	*ret;

	ret = (char *)ft_calloc(2, sizeof(char));
	if (!ret)
		return (FT_NULL);
	*ret = (char)c;
	return (ret);
}

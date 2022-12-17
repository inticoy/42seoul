/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 20:11:53 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/16 13:34:00 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	*ft_ctoa(int c)
{
	char	*ret;

	ret = (char *)ft_calloc(2, sizeof(char));
	if (!ret)
		return (FT_NULL);
	*ret = (char)c;
	return (ret);
}

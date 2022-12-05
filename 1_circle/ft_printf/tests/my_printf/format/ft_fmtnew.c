/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fmtnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 23:30:21 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/05 23:30:49 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "ft_printf.h"

t_format	*ft_fmtnew(void)
{
	t_format	*fmt;

	fmt = (t_format *)ft_calloc(1, sizeof(t_format));
	if (!fmt)
		return (FT_NULL);
	fmt->flag = (t_flag *)ft_calloc(1, sizeof(t_flag));
	if (!fmt->flag)
	{
		free(fmt);
		return (FT_NULL);
	}
	return (fmt);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tstrlstlen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:22:17 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/14 15:25:42 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_tstrlstlen(t_list *tstrlst)
{
	int	len;

	len = 0;
	while (tstrlst)
	{
		len += ((t_string *)tstrlst->content)->len;
		tstrlst = tstrlst->next;
	}
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tstrlst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:19:36 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/16 14:01:07 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	print_tstrlst(t_list *tstrlst)
{
	t_string	*tstr;
	int			wret;
	int			printed;

	printed = 0;
	while (tstrlst)
	{
		tstr = tstrlst->content;
		if (!tstr)
		{
			printed = -1;
			break ;
		}
		wret = write(1, tstr->str, tstr->len);
		if (wret < 0)
		{
			printed = -1;
			break ;
		}
		printed += wret;
		tstrlst = tstrlst->next;
	}
	return (printed);
}
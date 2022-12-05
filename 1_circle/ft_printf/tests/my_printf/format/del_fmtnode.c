/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_fmtnode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 23:27:51 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/05 23:28:15 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_printf.h"

void	del_fmtnode(t_format *format)
{
	if (format->flag)
		free(format->flag);
	free(format);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlstlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:27:41 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/05 23:15:31 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlstlen(t_list *strlst)
{
	int	len;

	len = 0;
	while (strlst)
	{
		len += ft_strlen(strlst->content);
		strlst = strlst->next;
	}
	return (len);
}

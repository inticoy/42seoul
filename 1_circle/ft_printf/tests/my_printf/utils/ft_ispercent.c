/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ispercent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:22:43 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/05 18:55:42 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_ispercent(int c)
{
	if (c == '%')
		return (1);
	else
		return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_padding.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:53:09 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/16 19:01:08 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdio.h>

static t_bool	isallzero(t_string *tstr)
{
	t_bool	ret;
	int		i;

	ret = ft_true;
	i = 0;
	while (i < tstr->len)
	{
		if (!ft_iszero(tstr->str[i]))
			ret = ft_false;
		i++;
	}
	return (ret);
}

static void	fill_background(char *str, t_format format)
{
	if (!format.flag.zero)
		ft_memset(str, ' ', format.width);
	else if (format.specifier == 'c')
		ft_memset(str, ' ', format.width);
	else if (format.specifier == 's')
		ft_memset(str, ' ', format.width);
	else if (format.specifier == 'p')
		ft_memset(str, ' ', format.width);
	else if (format.flag.left)
		ft_memset(str, ' ', format.width);
	else if (format.precision >= 0)
		ft_memset(str, ' ', format.width);
	else
		ft_memset(str, '0', format.width);
}

static t_string	*apply_padding(t_string *tstr, t_format format)
{
	char		*sret;
	t_string	*ret;

	sret = (char *)ft_calloc(format.width + 1, sizeof(char));
	if (!sret)
	{
		del_tstr(tstr);
		return (FT_NULL);
	}
	fill_background(sret, format);
	if (format.flag.left)
		ft_memcpy(sret, tstr->str, tstr->len);
	else if (need_prefix(format))
	{
		if (format.flag.zero && format.precision < 0 && !isallzero(tstr))
		{
			if (format.specifier == 'x')
				ft_memcpy(sret, "0x", 2);
			else if (format.specifier == 'X')
				ft_memcpy(sret, "0X", 2);
			ft_memcpy(sret + format.width - tstr->len + 2, tstr->str + 2, tstr->len - 2);
		}
		else
			ft_memcpy(sret + format.width - tstr->len, tstr->str, tstr->len);
	}
	else if (tstr->str[0] == '+' || tstr->str[0] == '-')
	{
		if (format.flag.zero && format.precision < 0)
			sret[0] = tstr->str[0];
		else
			sret[format.width - tstr->len] = tstr->str[0];
		ft_memcpy(sret + format.width - tstr->len + 1, tstr->str + 1, tstr->len - 1);
	}
	else if (need_space(format))
	{
		sret[0] = tstr->str[0];
		ft_memcpy(sret + format.width - tstr->len + 1, tstr->str + 1, tstr->len - 1);
	}
	else
		ft_memcpy(sret + format.width - tstr->len, tstr->str, tstr->len);
	ret = ft_tstrnew(sret, format.width, format.width + 1);
	del_tstr(tstr);
	return (ret);
}

t_string	*convert_padding(t_string *tstr, t_format format)
{
	if (!tstr)
		return (FT_NULL);
	else if (!need_padding(tstr, format))
		return (tstr);
	else
		return (apply_padding(tstr, format));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_padding.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:53:09 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/17 15:28:34 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_bool	is_all_zero(char *str, int len)
{
	t_bool	ret;
	int		i;

	ret = ft_true;
	i = 0;
	while (i < len)
	{
		if (str[i] != '0')
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

static size_t	get_prefixlen(t_string tstr, t_format format)
{
	size_t	len;

	if (is_all_zero(tstr.str, tstr.len))
		len = 0;
	else if (need_prefix(format) && format.precision < 0)
		len = 2;
	else if ((tstr.str[0] == '+' || tstr.str[0] == '-') && format.precision < 0)
		len = 1;
	else if (need_space(tstr, format))
		len = 1;
	else
		len = 0;
	return (len);
}

static t_string	apply_padding(t_string tstr, t_format format)
{
	size_t	i;
	char	*str;

	str = (char *)ft_calloc(format.width + 1, sizeof(char));
	if (!str)
	{
		ft_free_s(tstr.str);
		return (get_tstr_auto(FT_NULL));
	}
	fill_background(str, format);
	if (format.flag.left)
		ft_memcpy(str, tstr.str, tstr.len);
	else if (format.flag.zero && is_num_format(format))
	{
		i = get_prefixlen(tstr, format);
		ft_memcpy(str, tstr.str, i);
		ft_memcpy(str + format.width - tstr.len + i, \
					tstr.str + i, \
					tstr.len - i);
	}
	else
		ft_memcpy(str + format.width - tstr.len, tstr.str, tstr.len);
	ft_free_s(tstr.str);
	return (get_tstr(str, format.width, format.width + 1));
}

t_string	convert_padding(t_string tstr, t_format format)
{
	if (!tstr.str)
		return (tstr);
	else if (!need_padding(tstr, format))
		return (tstr);
	else
		return (apply_padding(tstr, format));
}

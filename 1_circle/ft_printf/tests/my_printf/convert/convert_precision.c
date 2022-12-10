/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_precision.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:53:09 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/10 21:49:43 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static t_bool	need_precision(t_format format)
{
	if (format.precision < 0)
		return (ft_false);
	else if (format.specifier == 'c')
		return (ft_false);
	else if (format.specifier == 'p')
		return (ft_false);
	else if (format.specifier == '%')
		return (ft_false);
	else
		return (ft_true);
}

static size_t	get_precisionlen(char *str, t_format format)
{
	size_t	slen;
	size_t	len;

	slen = ft_strlen(str);
	len = 0;
	if (ft_isnumfs(format.specifier))
	{
		if (ft_isminus(str[0]))
			len++;
		if (format.precision > (int)(slen - len))
			len += format.precision;
		else
			len = slen;
		if (ft_iszero(str[0]) && !format.precision)
			len = 0;
	}
	else if (ft_isstrfs(format.specifier))
	{
		if (format.precision < (int)slen)
			len = format.precision;
		else
			len = slen;
	}
	return (len);
}

static char	*precision(char *str, t_format format)
{
	const size_t	slen = ft_strlen(str);
	size_t			len;
	size_t			i;
	char			*ret;

	len = get_precisionlen(str, format);
	i = 0;
	ret = ft_calloc(len + 1, sizeof(char));
	if (!ret)
		return (FT_NULL);
	if (ft_isnumfs(format.specifier))
	{
		if (ft_isminus(str[i]))
			ret[i++] = str[i];
		ft_bzero(ret + i, len - slen);
		ft_strlcpy(ret + i + len - slen, str, slen - i + 1);
	}
	else if (ft_isstrfs(format.specifier))
		ft_strlcpy(ret, str, len + 1);
	ft_free_s(str);
	return (ret);
}

char	*convert_precision(char *str, t_format format)
{
	if (!str)
		return (FT_NULL);
	else if (need_precision(format))
		return (precision(str, format));
	else
		return (str);
}

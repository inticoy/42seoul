// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   convert_padding.c                                  :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/12/05 19:53:09 by gyoon             #+#    #+#             */
// /*   Updated: 2022/12/14 16:55:29 by gyoon            ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "libft.h"
// #include "ft_printf.h"

// static void	fill_background(char *str, t_format format)
// {
// 	if (!format.flag.zero)
// 		ft_memset(str, ' ', format.width);
// 	else if (format.specifier == 'c')
// 		ft_memset(str, ' ', format.width);
// 	else if (format.specifier == 's')
// 		ft_memset(str, ' ', format.width);
// 	else if (format.specifier == 'p')
// 		ft_memset(str, ' ', format.width);
// 	else if (format.flag.left)
// 		ft_memset(str, ' ', format.width);
// 	else if (format.precision)
// 		ft_memset(str, ' ', format.width);
// 	else
// 		ft_memset(str, '0', format.width);

// }

// static char	*padding(char *str, t_format format)
// {
// 	const size_t	slen = ft_strlen(str);
// 	char			*ret;

// 	ret = (char *)ft_calloc(format.width + 1, sizeof(char));
// 	if (!ret)
// 		return (FT_NULL);
// 	fill_background(ret, format);
// 	if (format.flag.left)
// 		ft_memcpy(ret, str, ft_strlen(str));
// 	else if (need_prefix(format))
// 	{
// 		if (format.flag.zero)
// 		{
// 			if (format.specifier == 'x')
// 				ft_memcpy(ret, "0x", 2);
// 			else if (format.specifier == 'X')
// 				ft_memcpy(ret, "0X", 2);
// 			ft_memcpy(ret + format.width - slen - 2, str + 2, slen - 2);
// 		}
// 		else
// 			ft_memcpy(ret + format.width - slen, str, slen);
// 	}
// 	ft_free_s(str);
// 	return (ret);
// }

// t_string	*convert_padding(t_string *tstr, t_format format)
// {
// 	if (!tstr)
// 		return (FT_NULL);
// 	else if (!need_padding(tstr, format))
// 		return (tstr);
// 	else
// 		return (padding(tstr, format));
// }

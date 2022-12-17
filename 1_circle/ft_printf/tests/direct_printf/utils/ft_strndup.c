/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:18:49 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/13 15:49:18 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	const size_t	slen = ft_strlen(s1);
	size_t			len;
	char			*ret;

	if (slen > n)
		len = n;
	else
		len = slen;
	ret = (char *) ft_calloc(len + 1, sizeof(char));
	if (!ret)
		return (0);
	return (ft_memcpy(ret, s1, len));
}

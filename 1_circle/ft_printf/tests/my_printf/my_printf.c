/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 21:34:02 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/04 18:15:53 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "./libft/libft.h"

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct s_flag
{
	t_bool	left;
	t_bool	sign;
	t_bool	space;
	t_bool	prefix;
	t_bool	zero;
}	t_flag;

typedef struct s_format
{
	t_flag	flag;
	int		width;
	int		precision;
	char	specifier;
}	t_format;

typedef struct s_string
{
	char	*str;
	int		len;
	int		size;
}	t_string;

t_format	get_format(const char *fmt)
{
	t_format	format;

	return (format);
}

t_string	convert_format(const char *fmt, t_format format)
{
	t_string	string;

	return (string);
}

int	ft_printf(const char *fmt, ...)
{
	int			len;
	t_format	format;
	t_string	string;

	len = 0;
	while (*fmt)
	{
		if (is_conversion(*fmt))
		{
			// format = get_format(fmt);
			// string = convert_format(fmt, format);
			// len += string.len;
			// print(string);
			// free(string.str);
		}
		else
		{
			printf("%c", *fmt);
			len++;
		}
	}
	return (len);
}

int	main(void)
{
	ft_printf("hello world!\n");
	printf("hello world!\n");
	return (0);
}

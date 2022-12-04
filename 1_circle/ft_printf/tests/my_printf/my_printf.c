/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 21:34:02 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/04 22:21:02 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "./libft/libft.h"

#define FT_NULL (void *)0

typedef enum e_bool
{
	FT_FALSE,
	FT_TRUE
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
	int		len;
	t_flag	*flag;
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

t_format	*ft_fmtnew(void)
{
	t_format	*format;

	format = (t_format *)ft_calloc(1, sizeof(t_format));
	format->flag = (t_flag *)ft_calloc(1, sizeof(t_flag));
	return (format);
}

t_bool	ft_ispercent(int c)
{
	if (c == '%')
		return (FT_TRUE);
	else
		return (FT_FALSE);
}

t_bool	ft_isflag(int c)
{
	if (c == '-' || c == '+' || c == ' ' || c == '#' || c == '0')
		return (FT_TRUE);
	else
		return (FT_FALSE);
}

void	set_flag(t_flag *flag, int c)
{
	if (c == '-')
		flag->left = 1;
	else if (c == '+')
		flag->sign = 1;
	else if (c == ' ')
		flag->space = 1;
	else if (c == '#')
		flag->prefix = 1;
	else if (c == '0')
		flag->zero = 1;
}

int	get_skip_digit(const char *str)
{
	int	len;

	len = 0;
	while (ft_isdigit(str[len]))
		len++;
	return (len);
}

t_bool	ft_isdot(int c)
{
	if (c == '.')
		return (FT_TRUE);
	else
		return (FT_FALSE);
}

t_format	*get_format(const char *fmt)
{
	t_format	*format;
	int			len;

	format = ft_fmtnew();
	len = 0;
	if (ft_ispercent(fmt[len]))
	{
		while (ft_isflag(fmt[++len]))
			set_flag(format->flag, fmt[len]);
		format->width = ft_atoi(fmt);
		len += get_skip_digit(fmt + len);
		if (ft_isdot(fmt[len]))
		{
			format->precision = ft_atoi(fmt + ++len);
			len += get_skip_digit(fmt + len);
		}
		format->specifier = fmt[len++];
		// if strange, len => 1
	}
	else
		while (fmt[len] && !ft_ispercent(fmt[len]))
			len++;
	format->len = len;
	return (format);
}

t_list	*get_formats(const char *fmt)
{
	t_list		*formats;
	t_format	*format;

	formats = ft_lstnew(ft_fmtnew());
	while (*fmt)
	{
		format = get_format(fmt);
		// printf("\nfmtnew : %d, %d, %d, %d\n", format->len, format->width, format->precision, format->specifier);
		// printf("flags : %d, %d, %d, %d, %d\n", format->flag->left, format->flag->sign, format->flag->space, format->flag->prefix, format->flag->zero);
		ft_lstadd_back(&formats, ft_lstnew(format));
		fmt += format->len;
	}
	return (formats);
}

void	prints(t_string *string)
{
	ft_putstr_fd(string->str, 1);
}

int	ft_stringlen(t_string *string)
{
	return (string->len);
}

int	get_strings_len(t_list *strings)
{
	int	len;

	len = 0;
	while (strings)
	{
		len += ft_stringlen(strings->content);
		strings = strings->next;
	}
	return (len);
}

t_string	*ft_strnew(void)
{
	t_string	*string;

	string = (t_string *)ft_calloc(1, sizeof(t_string));
	return (string);
}

t_string	*get_string(const char *fmt, t_format *format)
{
	t_string	*ret;

	ret = ft_strnew();
	ret->str = (char *)ft_calloc(format->len + 1, sizeof(char))
	ft_memcpy(ret->str, fmt, format->len);
	return (ret);
}

t_list	*get_strings(const char *fmt, t_list *formats)
{
	t_list		*strings;
	t_string	*string;

	strings = ft_lstnew(ft_strnew());
	while (*fmt)
	{
		string = get_string(fmt, formats);
		ft_lstadd_back(&strings, ft_lstnew(string));

		fmt += ((t_formats->content)->len;
	}
	return (strings);
}

int	ft_printf(const char *fmt, ...)
{
	t_list	*formats;
	t_list	*strings;
	int		printed;

	formats = get_formats(fmt);
	strings = get_strings(fmt, formats);
	ft_lstiter(&strings, prints);
	printed = get_strings_len(&strings);
	return (printed);
}

int	main(void)
{
	int	ft;
	int	original;

	ft = ft_printf("hello world!%-+000 .10d\n");
	original = printf("hello world!\n");
	printf("my : %d\noriginal : %d\n", ft, original);
	return (0);
}

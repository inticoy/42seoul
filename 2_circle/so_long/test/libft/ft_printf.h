/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:10:51 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/17 15:35:26 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

# ifndef FT_NULL
#  define FT_NULL (void *)0
# endif

typedef struct s_string
{
	char		*str;
	long long	len;
	long long	size;
}	t_string;

typedef enum e_bool
{
	ft_false,
	ft_true
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
	t_flag	flag;
	int		width;
	int		precision;
	char	specifier;
}	t_format;

t_string	convert_padding(t_string tstr, t_format format);
t_string	convert_precision(t_string tstr, t_format format);
t_string	convert_prefix(t_string tstr, t_format format);
t_string	convert_sign(t_string tstr, t_format format);
t_string	convert_space(t_string tstr, t_format format);

t_flag		init_flag(void);
t_bool		need_padding(t_string tstr, t_format format);
t_bool		need_precision(t_string tstr, t_format format);
t_bool		need_prefix(t_format format);
t_bool		need_sign(t_format format);
t_bool		need_space(t_string tstr, t_format format);
t_flag		update_flag(t_flag flag, int c);

t_format	get_formatf(const char *fmt);
t_format	init_format(void);
t_bool		is_num_format(t_format format);
t_bool		is_str_format(t_format format);

t_string	ft_tstrjoin(t_string ts1, t_string ts2);
t_string	get_tstr_auto(char *str);
t_string	get_tstr(char *str, int len, int size);
t_string	get_tstrf(const char *fmt, t_format format, va_list *args);

char		*ft_ctoa(int c);
char		*ft_ptoa(void *ptr);
t_string	ft_vtoa(char specifier, va_list *args);
char		*ft_utoa(unsigned int u);
char		*ft_xtoa(unsigned int num);

void		ft_free_s(void *ptr);
char		*ft_strtoupper(char *s);

int			ft_printf(const char *fmt, ...);

#endif
